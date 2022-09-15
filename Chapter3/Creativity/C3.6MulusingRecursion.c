#include<stdio.h>

int mul(int m , int n)
{
    int mu = 0;
    if(n > 1)
    {
         mu = mu + mul(m , n -1);
         return m;
    }
    else if(n == 1)
    {
        return m;
    }
    else
    {
        return mu;
    }
    
}

int main()
{
    printf("%d",mul(5,6));
}