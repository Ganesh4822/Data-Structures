/*
C-3.13 Describe a recursive function for converting a string of digits into the integer it represents.
 For example, "13531" represents the integer 13,531.
*/

#include<iostream>
#include<string>

void StringToInt(std::string charSet,int *n)
{
    if(charSet.length() == 1)
    {
        *n = 10* (*n) +charSet[0] - '0';
        return;
    }
        

    *n = 10 * (*n) + (charSet[0] - '0');
    StringToInt(charSet.substr(1),n);
    return;
}


int main()
{
    int n = 0;
    std::string sample = "348242";
    StringToInt(sample,&n);
    std::cout<<"number is"<<n;
}