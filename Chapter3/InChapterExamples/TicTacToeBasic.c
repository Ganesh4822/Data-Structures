#include<stdio.h>
#include<stdlib.h>

const int X = 1;
const int O = -1;
const int EMPTY = 0;

int board[3][3];
int CurrentPlayer;

void clearBoard()
{
    for(int i =0 ;i < 3 ;i++)
        for(int j = 0; j< 3 ;j++)
            board[i][j] = EMPTY;
    
    CurrentPlayer = X;
}


void putMark(int i, int j)
{
    board[i][j] = CurrentPlayer;
    CurrentPlayer = -CurrentPlayer; //switchPlayer

}

int isWin(int mark)
{
    int win = 3* mark;

    return ((board[0][0] + board[0][1] + board[0][2] == win) 
    || (board[1][0] + board[1][1] + board[1][2] == win) 
    || (board[2][0] + board[2][1] + board[2][2] == win) 
    || (board[0][0] + board[1][0] + board[2][0] == win) 
    || (board[0][1] + board[1][1] + board[2][1] == win) 
    || (board[0][2] + board[1][2] + board[2][2] == win) 
    || (board[0][0] + board[1][1] + board[2][2] == win) 
    || (board[2][0] + board[1][1] + board[0][2] == win));

}


int getWinner()
{
    if(isWin((X)))
        return X;
    else if(isWin((O)))
        return O;
    else 
        return EMPTY;
    
}


void PrintBoard()
{
    char X = 'X';
    char O = 'O';
    for(int i =0 ; i< 3; i++)
    {
        for(int j = 0 ; j <3 ;j++)
        {
            switch(board[i][j])
            {
                case 1: 
                    printf("%c",X);
                    break;
                case -1:
                    printf("%c",O);
                    break;
                case 0:
                    printf(" ");
                    break;

            }
            if(j<2)
                printf("|");
        }
        if(i<2)
            printf("\n-+-+-\n");
    }
}



int main()
{
    clearBoard();
    putMark(0,0);
    putMark(1,1);
    putMark(0,1);
    putMark(0,2);
    putMark(2,0);
    putMark(1,2);
    putMark(2,2);
    putMark(2,1);
    putMark(1,0);
    PrintBoard();
    int winner = getWinner();
    printf("%d",winner);
}

