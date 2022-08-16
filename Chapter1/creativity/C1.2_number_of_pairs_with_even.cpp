#include<iostream>

int count_number_of_pairs(int* arr, int n);

int main()
{
    int* arr;
    int n = 10;
    arr = (int*)malloc(10*sizeof(int));

    for(int i = 0 ; i < 10 ; i++)
    {
        arr[i]  = i;
    }
    int pairs = count_number_of_pairs(arr, n);
    
    std::cout<<"number of pairs is = " << pairs <<std::endl;
    free(arr);
}


int count_number_of_pairs(int* arr, int n)
{
    int c = 0;
    for(int i = 0 ; i< n - 1; i++)
    {
        for(int j = i; j< n ; j++)
        {
            if((arr[i] * arr[j]) % 2 == 0)
            {
                c += 1;

            }
        }
    }
    return c;
}