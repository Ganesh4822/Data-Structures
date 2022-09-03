/*
R-3.4 Describe a way to use recursion to compute the sum of all the elements in
a n×n (two-dimensional) array of integers.
*/

// INCOMPLTE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

typedef int (*pComputeSum)(void**);


int** ReturnMatrixPointer(int n);
void FillMatrix(int**,int);
int ComputeSum(void**,int);
void PrintMatrix(int** M , int n);

int main()
{
    int**M = ReturnMatrixPointer(5);
    FillMatrix(M,5);
    PrintMatrix(M,5);
}

int** ReturnMatrixPointer(int n)
{
   int** M = (int**)malloc(sizeof(int*)*n);
    int i;
   for(i = 0 ; i< n;i++)
   {
        M[i] = (int*)malloc(sizeof(int)*n);
   } 

   return M;
}

void FillMatrix(int** M,int n)
{
    srand(time(0));
    int i,j;
    for(i = 0; i< n; i++)
    {
        for( j =0 ; j< n ; j++)
        {
            M[i][j] = (rand() % INT_MAX);
        }
    }
}

void PrintMatrix(int** M , int n)
{
    int i,j;
    for(i = 0; i < n ; i++)
    {
        for(j = 0 ; j< n ; j++)
        {
            printf("%d \t",M[i][j]);
        }
        printf("\n");

    }
}



int ComputeSum(int** M ,int n , int  i, int j)
{
    
    int sum = 0;
    int i,j;


    
    

}

int row_sum(int** M, int n, int i)
{
    int sum = 0;
    int j;
    for(j = 0; j< n ;j++)
    {
            sum = sum + M[i][j];
    }
    return sum;
}