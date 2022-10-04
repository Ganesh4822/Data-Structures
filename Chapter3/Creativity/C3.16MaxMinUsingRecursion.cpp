#include<iostream>

int FindMinimum(int A[],int n)
{
    if(n ==1)
        return A[0];
    return __min(A[n-1],FindMinimum(A,n-1));
}

int main()
{
    int A[]  = {1,2,233,12,121,2343};
    std::cout<<"Minimum is"<<FindMinimum(A,6);
}