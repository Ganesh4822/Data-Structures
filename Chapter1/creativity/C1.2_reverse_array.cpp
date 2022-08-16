#include<iostream>

void reverse_array(int* arr, int n);

int main()
{
    int* arr;
    int n = 10;
    arr = (int*)malloc(10*sizeof(int));

    for(int i = 0 ; i < 10 ; i++)
    {
        arr[i]  = i;
    }
    reverse_array(arr, n);
    

    for(int i = 0; i< n; i++)
    {
        std::cout<<arr[i]<<"\t";
    }

    free(arr);

}


void reverse_array(int* arr , int n)
{
    for(int i = 0 ; i< n/2 ;i++)
    {
        int temp = arr[(n-1)-i];
        arr[(n-1)-i] = arr[i];
        arr[i] = temp; 
    }
}