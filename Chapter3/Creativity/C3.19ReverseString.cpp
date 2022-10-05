/*
C-3.19 Write a short recursive C++ function that takes a character string s and
outputs its reverse. So for example, the reverse of "pots&pans" would
be "snap&stop"
*/

#include<iostream>

void Reverse(std::string str,int s, int e)
{
    
    if(s == e)
     return;
    char temp  = str[e];
    str[e] = str[s];
    str[s] = temp;
    std::cout<<str<<std::endl;
    if(s < e )
    {
        Reverse(str,s+1,e-1);
    }
}


int main()
{
    std::string str = "pots&pans";
    Reverse(str,0,str.length());

    std::cout<<str<<std::endl;
}