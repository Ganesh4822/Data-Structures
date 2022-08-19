/*
P-2.1 Write a C++ program that can take a positive integer greater than 2 as
input and write out the number of times one must repeatedly divide this
number by 2 before getting a value less than 2.
*/


#include<stdio.h>

int divide_by_2(int* num);

int main()
{   int num;
    scanf("%d",&num);
    printf("%d",divide_by_2(&num));
}

int divide_by_2(int* num)
{
    int count;
    count =0;
    while(*num > 2)
    {
        *num /= 2;
        count++;
    }
    return count;
}

