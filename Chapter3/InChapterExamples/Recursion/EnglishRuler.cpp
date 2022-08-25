#include<iostream>
#include<windows.h>

void drawOneTick(int TickSize, int label = -1);
void drawTicks(int TickLength);
void DrawRuler(int nInches, int MajorLength);

int main()
{
    DrawRuler(5,4);
}

void drawOneTick(int TickSize, int label)
{
    for(int i = 0 ; i < TickSize ; i++)
    {
        std::cout<<"-";
    }
    if(label >= 0)
        std::cout<<" "<<label;
    std::cout<<std::endl;
}

void drawTicks(int TickLength)
{
    if(TickLength > 0)
    {
        drawTicks(TickLength -1);
        Sleep(1000);
        drawOneTick(TickLength);
        Sleep(1000);
        drawTicks(TickLength - 1);
    }
}

void DrawRuler(int nInches, int MajorLength)
{   
    drawOneTick(MajorLength,0);
    for(int i = 1; i < nInches ; i++)
    {
        drawTicks(MajorLength -1 );
        drawOneTick(MajorLength,i);
    }
        
}