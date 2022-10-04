/*
C-3.20 Write a short recursive C++ function that determines if a string s is a
palindrome, that is, it is equal to its reverse. For example, "racecar"
and "gohangasalamiimalasagnahog" are palindromes.
*/
#include<iostream>


bool IsPalindrome(std::string str,int s, int e)
{
    if(s == e)
        return true;
    if(str[s] != str[e] )
        return false;
    
    if(s < e +1)
    {
        return IsPalindrome(str,s+1,e-1);
    }

    return true;
}



int main()
{
    std::string str = "gohangasalamiimalasagnahog";
    std::cout<<IsPalindrome(str,0,str.length());
}