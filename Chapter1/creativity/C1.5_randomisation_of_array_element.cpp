/*
Write a C++ function that takes an array containing the set of all integers
in the range 1 to 52 and shuffles it into random order. Use the built-in function rand, which returns a pseudo-random integer each time it is called.
Your function should output each possible order with equal probability.
*/

#include<iostream>

void array_randomisor(int *arr, int n);
int get_random_number(void);
void swap( int* n1, int*n2);

int main()
{
    int arr[52];
    for(int i = 0; i< 52 ; i++)
    {
        arr[i] = i;
    }
    array_randomisor(arr,52);

    for(int i = 0; i< 52 ; i++)
    {
        std::cout<<"\t"<<arr[i];
    }
    std::cout<<std::endl;

}




void array_randomisor(int *arr, int n)
{
    for(int i = 0 ; i< 52 ; i++)
    {
        swap(&arr[i], &arr[52 - get_random_number()] );
    }
    
}

int get_random_number(void)
{
    return (rand()% 52);   
}

void swap( int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}