#include<stdio.h>
#include<ctype.h>
#include<unistd.h>
#include<termios.h>
#include<errno.h>
#include<stdlib.h>
/***defines***/
#define CTRL_KEY(k) ((k) & 0x1f)
/***data***/

struct termios orig_termios;
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
    if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&orig_termios) == -1)
    die("tcsetattr");

}

void enableRawMode()
{
    if(tcgetattr(STDIN_FILENO,&orig_termios) == -1) die("tcgetattr");
    atexit(disableRawMode);
    struct termios raw = orig_termios;
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

/***input***/

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
    for(y = 0 ; y < 24 ; y++)
    {
        write(STDOUT_FILENO,"~\r\n",3);
    }
}
void RefreshSreen()
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
    char c = '\0';
    while(1)
    {
        RefreshSreen();
        processKeyPress();
        
    }
    return 0;
}
