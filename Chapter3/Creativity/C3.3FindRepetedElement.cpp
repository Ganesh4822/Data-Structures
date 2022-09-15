/*
C-3.3 Let A be an array of size n ≥ 2 containing integers from 1 to n−1, inclusive, with exactly one repeated. Describe a fast algorithm for finding the
integer in A that is repeated.
*/

#include<iostream>

int FindRepetative(int* arr, int n)
{
    for(int i = 0; i < n ;i++)
    {
        if(arr[arr[i]] > 0)
        {
           arr[arr[i]] = -arr[arr[i]]; 
        }
        else
        {
            return -arr[arr[i]];
        }
    }
}

int main()
{
    int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
    int *a = arr;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    std::cout << FindRepetative(a, N);
 
    return 0;
}