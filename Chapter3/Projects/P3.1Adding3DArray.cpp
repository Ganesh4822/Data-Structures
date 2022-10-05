/*
P-3.1 Write a C++ function that takes two three-dimensional integer arrays and
adds them componentwise.
*/

#include<iostream>
#include<cTime>
#include<chrono>

int*** return3DArray(int x,int y ,int z);
void Fill3DArray(int *** M, int x,int y,int z);
void FreeMemory(int*** ,int ,int,int);

int*** AdditionOfTwo3DMatrix(int***,int***,int ,int,int);
void PrintMatrix(int*** M , int x ,int y, int z);


int main()
{   
    srand(time(NULL));
    std::cout<<"Hello"<<std::endl;
    int*** M  = return3DArray(2,3,5);
    std::cout<<"M = "<<M<<std::endl;
   
    std::cout<<"Hello"<<std::endl;
    Fill3DArray(M,2,3,5);
    int*** N = return3DArray(2,3,5);
    std::cout<<"N = "<<N<<std::endl;
    Fill3DArray(N,2,3,5);

    std::cout<<"M matrix"<<std::endl;
    PrintMatrix(M,2,3,5);
    std::cout<<"N matrix"<<std::endl;
    PrintMatrix(N,2,3,5);
    int*** sum = AdditionOfTwo3DMatrix(M,N,2,3,5);
    std::cout<<"Sum = "<<std::endl;
    PrintMatrix(sum,2,3,5);

    FreeMemory(N,2,3,5);
    FreeMemory(M,2,3,5);
    FreeMemory(sum,2,3,5);
}

int*** return3DArray(int x, int y, int z)
{
    int ***A = (int***)malloc(sizeof(int**)* x);

    for(int i = 0; i< x ; i++)
    {
        A[i] = (int**)malloc(sizeof(int*)*y);
        for(int j = 0 ; j < y ;j++)
        {
            A[i][j] = (int*)malloc(sizeof(int)*z);
        } 
    }

     return A;
}

void Fill3DArray(int *** M, int x,int y,int z)
{   
    
    
    for(int i = 0 ; i < x ;i++)
    {
        for(int j = 0 ;j< y ; j++)
        {
            for(int k = 0; k < z ; k++)
            {
                M[i][j][k] = (rand()  % (INT_MAX/4));  
            }
        }
    }    
}

int*** AdditionOfTwo3DMatrix(int*** M,int*** N,int x,int y,int z)
{
    int*** sum = return3DArray(x,y,z);
    for(int i = 0; i < x ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            for(int k = 0; k < z ; k++)
            {
                sum[i][j][k] = M[i][j][k] + N[i][j][k];
            }
        }
    }  

    return sum; 
}



void FreeMemory(int*** M ,int x ,int y,int z)
{
    for(int i = 0 ; i <x ; i++)
    {   
        for(int j = 0; j< y ; j++)
        {
            free(M[i][j]);
        }
        free(M[i]);
    }

    free(M);    
}

void PrintMatrix(int*** M , int x ,int y, int z)
{
    for(int i = 0; i < x ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            for(int k = 0; k < z ; k++)
            {
                std::cout<<"\t"<<M[i][j][k];
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    } 
}