#include<stdio.h>
#include<ctype.h>
#include<unistd.h>
#include<termios.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/ioctl.h>
/***defines***/
#define CTRL_KEY(k) ((k) & 0x1f)
/***data***/
struct EditorConfig{
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

/***input***/

void initEditor()
{
    if(getWindowSize(&E.screenRows , &E.screencols) == -1)die("GetwindowSize");
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
    }
}

/***output***/

void editorDrawRows()
{
    int y;
    for(y = 0 ; y < E.screenRows ; y++)
    {
        write(STDOUT_FILENO,"~",1);
        if(y < E.screenRows - 1)
            write(STDOUT_FILENO,"\r\n",3);
    }
}
void RefreshScreen()
{
    write(STDOUT_FILENO, "\x1b[2J",4);
    write(STDOUT_FILENO,"\x1b[H",3);

    editorDrawRows();

    write(STDOUT_FILENO,"\x1b[H",3);

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
