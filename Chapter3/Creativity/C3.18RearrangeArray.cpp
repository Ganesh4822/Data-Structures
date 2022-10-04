/*
C-3.18 Write a short recursive C++ function that will rearrange an array of int
values so that all the even values appear before all the odd values.
*/

#include<iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void Rearrange(int A[], int n, int cur)
{
    if((n == 1) || (cur >= n))
        return;
    
    while(A[cur] % 2 == 0)
    {
        cur++;
        std::cout<<"if"<<cur<<std::endl;
        //Rearrange(A,n,cur);
    }   
    if(A[cur] % 2 != 0 && A[n-1] %2 == 0)
    {
        std::cout<<"2nd if before swap "<<cur<<"-"<<n-1<<std::endl;
        swap(&A[cur],&A[n-1]);
        cur++;
        std::cout<<"2nd if"<<cur<<"-"<<n-1<<std::endl;
        Rearrange(A,n-1,cur);
    }
    else
    {
        std::cout<<"else"<<cur<<"-"<<n-1<<std::endl;
        Rearrange(A,n-1,cur);
    }
}


int main()
{
    int A[] = {2,123,32,12,43,4523,34,54,23323,5545,231,21,343,123,454,56,313,46};
    int n = sizeof(A)/sizeof(int);
    Rearrange(A,n,0);
    for(int i = 0; i < n ;i++)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}