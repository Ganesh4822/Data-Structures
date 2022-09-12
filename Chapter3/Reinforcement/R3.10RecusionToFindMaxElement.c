/*
R-3.11 Describe a recursive algorithm for finding the maximum element in an
array A of n elements. What is your running time and space usage?
*/

#include<stdio.h>

int FindMax(int*, int);

int main()
{
    int n;
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    int i;
    for(i = 0; i< n ; i++)
        scanf("%d",&arr[i]);
    
    int Max = FindMax(arr,n-1);
    printf("%d\n",Max);
    free(arr);
    arr = NULL;

}


int FindMax(int* a, int n)
{
    int max;
    if(n == 1)
    {
        max = a[0];
        return max;
    }
    else {
        max = a[n] > FindMax(a,n-1) ? a[n] : FindMax(a,n-1);
        return max;
    }
}