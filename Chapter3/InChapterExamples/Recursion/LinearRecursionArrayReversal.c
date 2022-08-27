#include<stdio.h>

void ArrayReversal(int* arr, int i ,int j);
void IterativeArrayReversal(int* arr, int i,int j);
void swap(int*, int*);

int main()
{
    int arr[]= {43,23,6,7,3,2,5,8,3,23,65,89};
    int n = sizeof(arr)/sizeof(int);
    printf("array size = %d\n",n);
    printf("Before :: ");
    for(int i = 0 ; i< n ;i++)
    {
        printf(" %d \t",arr[i]);
    }
    printf("\n");
    printf("After ::");
    IterativeArrayReversal(arr,0,n-1);
    for(int i = 0 ; i< n ;i++)
    {
        printf(" %d \t",arr[i]);
    }

}

void ArrayReversal(int* arr, int i ,int j)
{
    if(i < j)
    {
        swap(&arr[i],&arr[j]);
        ArrayReversal(arr,i+1,j - 1);
    }
        
    return;
}

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;

}



void IterativeArrayReversal(int* arr, int i,int j)
{
    while(i < j)
    {
        swap(&arr[i],&arr[j]);
        i = i + 1;
        j = j -1;
    }
    return;
}