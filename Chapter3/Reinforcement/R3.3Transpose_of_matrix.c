/*
R-3.3 Give a C++ code fragment that, given a n × n matrix M of type float,
replaces M with its transpose. Try to do this without the use of a temporary
matrix.
*/
#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
#include<limits.h>

void TransposeOfMatrix(float* matrix,int n);
float** ReturnMatrixPointer(int n);
void FillMatrix(float**,int);
void PrintMatrix(float**, int);

int main()
{

    float** M = ReturnMatrixPointer(5,5);
    FillMatrix(M,5,5);
    PrintMatrix(M,5,5);

    
}

float**ReturnMatrixPointer(int n)
{
    float** M = (float**)malloc(sizeof(float*)*n);

    for(int i = 0; i < n; i++)
    {
        M[i] = (float*)malloc(sizeof(float)* n); 
    }
    
    return M;
}

void FillMatrix(float** M, int n)
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

void PrintMatrix(float** M , int n)
{
    int i,j;
    for(i = 0; i < n ; i++)
    {
        for(j = 0 ; j< n ; j++)
        {
            printf("%f \t",M[i][j]);
        }
        printf("\n");

    }
}



