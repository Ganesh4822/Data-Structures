/*
R-3.3 Give a C++ code fragment that, given a n × n matrix M of type float,
replaces M with its transpose. Try to do this without the use of a temporary
matrix.
*/
#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
#include<limits.h>

void TransposeOfMatrix(float**,int,int,int);
float** ReturnMatrixPointer(int n);
void FillMatrix(float**,int);
void PrintMatrix(float**, int);
void swap(float* a, float* b);
void FreeMemory(void**,int);

int main()
{

    float** M = ReturnMatrixPointer(100);
    FillMatrix(M,100);
    printf("BEFORE---\n");
    PrintMatrix(M,100);
    TransposeOfMatrix(M,0,0,100);
    printf("AFTER-----\n");
    PrintMatrix(M,100);
    FreeMemory((void**)M,100);
    printf("-----------------------SUCCESS---------------------------\n");

}

float** ReturnMatrixPointer(int n)
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

void TransposeOfMatrix(float** M,int i, int j , int n)
{
    int k; 
    for( k = j; k < n ;k++)
    {
        if(i != k)
        {
            int temp = M[i][k];
            M[i][k] = M[k][i];
            M[k][i] = temp;
        }

    }
    if((i + 1)<n && (j +1) < n)
    {
        TransposeOfMatrix(M,i+1,j+1,n);
    }
    else
    {
        return;
    }
}

//TransposeOfMatrix(M,0,0,5);
//TransposeOfMatrix(M,1,1,5);
//TransposeOfMatrix(M,2,2,5);
//TransposeOfMatrix(M,3,3,5);
//TransposeOfMatrix(M,4,4,5);



// transpose(M,i,j,n)
// {
//     int k;
//     for(k = j; k < n; j++)
//     {
//         swap(M[i][k],M[k][i]);
//     }
//     if( n - 1 != 0)
//     transpose(M,i+1,j+1,n-1);
// }


void FreeMemory(void** M,int n)
{
    int i;
    for(i = 0 ; i< n ; i++)
    {
        free(M[i]);
    }
    free(M);
    M = NULL;
}
