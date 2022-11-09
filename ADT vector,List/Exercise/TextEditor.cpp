/*
Write a simple text editor, which stores a string of characters using the list
ADT, together with a cursor object that highlights the position of some
character in the string (or possibly the position before the first character).
Your editor should support the following operations and redisplay the current text (that is, the list) after performing any one of them.
*/
#include<iostream>
#include<cassert>
#include<fstream>

typedef struct Node
{
    char charstring[80];
    Node* next;
    Node* prev;
}Line;

Line* currentLine;
Line* firstLine;
Node* head;
Node* tail;
int col;

void creatFirstLine()
{
    Node* p;
    p = new Node;
    currentLine = p;
    head = p;
    tail = p;
    col = -1;
}

void createNewLine()
{
    Node* p;
    p = new Node;
    p->next = NULL;
    if(head == NULL)
    {
        head = p;
        tail =p;
    }
    else
    {
        tail->next = p;
        p->prev = tail;
    }
    tail = p;
    currentLine = p;
}

void newLine()
{
    Node* p = new Node;
    p->next = NULL;
    p->prev = currentLine;
    currentLine->next = p;
    currentLine = p;
    col = 0;
}

int main()
{
    std::cout<<"Text Editor : ";
    char string[30];
    std::cin.getline(string,30);
    std::ifstream instream;
    instream.open(string);

    char reading;
    currentLine = firstLine;
    creatFirstLine();

    while(instream.read(&reading,sizeof(char)))
    {
        if(reading == '\n')
            newLine();
        else
        {
            col++;
            currentLine->charstring[col] = reading;
        }
    }
    instream.close();
}


