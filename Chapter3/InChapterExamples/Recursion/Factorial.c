#include<stdio.h>

int factorial(int n)
{
    if(n = 0)
        return 0;
    else
        return n * factorial(n-1);
}


int main()
{
    printf("%d",factorial(4));
}