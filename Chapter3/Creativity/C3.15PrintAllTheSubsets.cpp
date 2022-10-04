/*
C-3.15 Write a recursive C++ program that will output all the subsets of a set of
n elements (without repeating any subsets).
*/
#include<iostream>
#include<string>

void powerSet(std::string str, int index = -1, std::string curr = "")
{
    int n = str.length();
    if(index == n )
        return;
    std::cout<<curr<<"\n";

    for(int i = index + 1; i< n ; i++)
    {
        curr += str[i];
        powerSet(str,i,curr);
        curr.pop_back();
    }
    return;

}


int main()
{
    std::string str = "abc";
    powerSet(str);

}