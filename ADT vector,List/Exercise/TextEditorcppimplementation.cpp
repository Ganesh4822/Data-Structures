
/*
P-6.3 Write a simple text editor, which stores a string of characters using the list
ADT, together with a cursor object that highlights the position of some
character in the string (or possibly the position before the first character).
Your editor should support the following operations and redisplay the current text (that is, the list) after performing any one of them.
• left: Move cursor left one character (or nothing if at the beginning)
• right: Move cursor right one character (or do nothing if at the end)
• delete: Delete the character to the right of the cursor (or do nothing
if at the end)
• insert c: Insert the character c just after the cursor
*/

#include<iostream>
#include<fstream>

typedef struct Node 
{
    char str[80];
    Node* next;
    Node* prev;

}Line;

class TextEditor
{
    private:
        Line* currentline;
        Line* Fistline;
        Node* head;
        Node* tail;
        int col;

    public:
        TextEditor()
        {
            Line* line = new Line;
            currentline = Fistline = line;
            head = currentline;
            tail = currentline;
            col = 0;
        }

        void addLine()
        {
            Line* line = new Line;
            line->next = nullptr;
            line->prev = currentline;
            currentline = line;
            tail = line;
            col = 0;
        }

        void Swrite()
        {
            std::cout<<"Text Editor : ";
            char str[30];
            std::cin.getline(str,30);
            std::cout<<"string is "<<str<<std::endl;
            std::ifstream instream(str);
            std::cout<<"Here"<<std::endl;
            instream.open(str);
            std::cout<<"String is opened to read"<<std::endl;
            char reading;
            //currentline = Fistline;
            std::cout<<"reading Text"<<std::endl;
            while(instream.read(&reading, sizeof(reading)))
            {
                std::cout<<"here while"<<std::endl;
                if(reading == '\n')
                    break;
                else
                {
                    col++;
                    this->currentline->str[col] = reading;
                }
            }

        }
        
};

int main()
{
    TextEditor* T = new TextEditor();
    T->Swrite();
    std::cout<<"Ganesh You are great";

}