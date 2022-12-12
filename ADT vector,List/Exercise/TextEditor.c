    #include<stdio.h>
    #include<ctype.h>
    #include<unistd.h>
    #include<termios.h>
    #include<errno.h>
    #include<stdlib.h>
    #include<sys/ioctl.h>
    #include<string.h>
    /***defines***/
    #define GEDITOR "0.0.1"
    #define CTRL_KEY(k) ((k) & 0x1f)
    /***data***/
    struct EditorConfig{
    int cx;
    int cy;
    int screenRows;
    int screencols;
    struct termios orig_termios;

    };

    struct EditorConfig E;

    /***terminal***/

    void die(const char* s)
    {
        write(STDOUT_FILENO, "\x1b[2J",4);
        write(STDOUT_FILENO,"\x1b[H",3);
        perror(s);
        exit(1);
    }

    void disableRawMode()
    {
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&E.orig_termios) == -1)
        die("tcsetattr");

    }

    void enableRawMode()
    {
        if(tcgetattr(STDIN_FILENO,&E.orig_termios) == -1) die("tcgetattr");
        atexit(disableRawMode);
        struct termios raw = E.orig_termios;
        raw.c_iflag &= ~(IXON |ICRNL);
        raw.c_oflag &= ~(OPOST);
        raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
        tcsetattr(STDIN_FILENO,TCSAFLUSH, &raw);
    }

    char editorReadKey()
    {
        int nread;
        char c;
        while((nread = read(STDIN_FILENO,&c,1)) != 1)
        {
            if(nread == -1 &&errno != EAGAIN) die("Read");

        }
        return c;

    }

    int getCursorPosition(int *rows, int *column)
    {
        char buf[32];
        unsigned int i = 0;

        if(write(STDOUT_FILENO, "\x1b[6n",4) != 4) return -1;

        while(i  <  sizeof(buf) - 1)
        {
            if(read(STDIN_FILENO, &buf[i], 1) != 1)break;
            if(buf[i] == 'R')break;
            ++i;
        }

        buf[i] = '\0';
        if(buf[0] != '\x1b' || buf[1] != '[') return -1;
        if(sscanf(&buf[2], "%d;%d",rows,column)!= 2) return -1;
        return 0;
    }

    int getWindowSize(int *rows, int *cols)
    {
        struct winsize ws;
        if(ioctl(STDOUT_FILENO,TIOCGWINSZ,&ws) == -1 || ws.ws_col == 0)
        {
            if(write(STDOUT_FILENO, "\x1b[999C\x1b[999B]",12) != 12) return -1;
            return getCursorPosition(rows,cols);
        }
            
        else{
            *cols = ws.ws_col;
            *rows = ws.ws_row;
            return 0;
        }

    }

    /***Append buffer***/
    struct abuf{
        char *b;
        int len;
    };

    #define ABUF_INIT {NULL,0};

    void abAppend(struct abuf* ab, const char* newstring, int leng)
    {
        char* newbuf = (char*)realloc(ab->b, ab->len + leng);

        if(newbuf == NULL) return;
        //newString is Copied to the buffer from the last index of string that is already present in buffer.
        //Realloc will will give us the extra memory needed to store the appending string . It will either
        //give the extra memory in current block  or it will free the current block and give us the new memeory block.

        memcpy(&newbuf[ab->len], newstring, leng);
        ab->b = newbuf;
        ab->len += leng;
    }

    void freeBuff(struct abuf* ab)
    {
        free(ab->b);
    }

    /***input***/

    void initEditor()
    {
        E.cx = 0;
        E.cy = 0;
        if(getWindowSize(&E.screenRows , &E.screencols) == -1)die("GetwindowSize");
    }

    void MoveCurser(char key)
    {
        switch (key)
        {
        case 'w':
            E.cy--;
            break;
        case 's':
            E.cy++;
            break;
        case 'a':
            E.cx--;
            break;
        case 'd':
            E.cx++;
            break;
        }
    }

    void processKeyPress()
    {
        char c = editorReadKey();
        switch(c)
        {
            case CTRL_KEY('q'):
            write(STDOUT_FILENO, "\x1b[2J",4);
            write(STDOUT_FILENO,"\x1b[H",3);
            exit(0);
            break;
            case 'w':
            case 's':
            case 'a':
            case 'd':
                MoveCurser(c);
                break;

        }
    }

    /***output***/

    void editorDrawRows(struct abuf* ab)
    {
        int y;
        for(y = 0 ; y < E.screenRows ; y++)
        {
            if(y == E.screenRows/3){
                char welcome[80];
                int welcomelen = snprintf(welcome,sizeof(welcome),"GEDITOR -- version %s",GEDITOR);
                if(welcomelen > E.screencols) welcomelen = E.screencols;
                int padding = (E.screencols - welcomelen)/2;
                if (padding) {
                abAppend(ab, "~", 1);
                padding--;
                }
                while (padding--) abAppend(ab, " ", 1);
                abAppend(ab,welcome,welcomelen);
            }
            else
            {
                abAppend(ab,"~",1);    
            }
            //write(STDOUT_FILENO,"~",1);
            
            abAppend(ab, "\x1b[K", 3);
            if(y < E.screenRows - 1){
                //write(STDOUT_FILENO,"\r\n",2);
                abAppend(ab,"\r\n",2);
            }
                
        }
    }
    void RefreshScreen()
    {
        struct abuf ab = ABUF_INIT;

        //write(STDOUT_FILENO, "\x1b[2J",4);
        //write(STDOUT_FILENO,"\x1b[H",3);
        abAppend(&ab, "\x1b[?25l",6);
        //abAppend(&ab,"\x1b[2J",4);
        abAppend(&ab,"\x1b[H",3);

        editorDrawRows(&ab);
        char buf[32];
        snprintf(buf,sizeof(buf),"\x1b[%d;%dH",E.cy + 1,E.cx +1);
        abAppend(&ab,buf,strlen(buf));

        //write(STDOUT_FILENO,"\x1b[H",3);
        //abAppend(&ab,"\x1b[H",3);
        abAppend(&ab, "\x1b[?25h", 6);


        write(STDOUT_FILENO,ab.b,ab.len);

    }

    /***init***/
    int main()
    {
        
        enableRawMode();
        initEditor();
        char c = '\0';
        while(1)
        {
            RefreshScreen();
            processKeyPress();
            
        }
        return 0;
    }
