#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long ssize_t;
void fillArray(int* arr ,ssize_t N);
void show_array(int *arr, ssize_t N,char* msg);
void insert_at_sorting_position(int *arr, ssize_t N);
void sort(int *arr, ssize_t N);

int main(int argc, char** argv)
{
    int* a = NULL;
    ssize_t N = 0;
    if(argc != 2)
    {
        fprintf(stderr,"Wrong Number of Arguments");
        exit(EXIT_FAILURE);
    }

    N = atoll(argv[1]);

    if(N <= 0)
    {
        fprintf(stderr,"Wrong NUmber of Arguments provided");
        exit(EXIT_FAILURE);
    }
    printf("Here - 1\n");

    a = (int*) malloc(sizeof(int)* N);

    fillArray(a,N);
    show_array(a,N,"Array before sorting");
    sort(a,N);
    show_array(a,N,"Array after sorting");

    free(a);
}

void fillArray(int* arr ,ssize_t N)
{
    ssize_t i ;
    srand(time(0));

    for(i = 0 ; i < N ; i++)
    {
        arr[i] = rand();
    }
}

void show_array(int *arr, ssize_t N,char* msg)
{
     ssize_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("p[%lld]:%d\n", i, arr[i]); 
}


void insert_at_sorting_position(int *arr, ssize_t N)
{
    int key;
    ssize_t i;
    i = N-2;
    key = arr[N-1];

    while(i > -1 && arr[i] > key)
    {
        arr[i+1] = arr[i];
        i = i -1;
    }
    arr[i + 1] = key;
}

void sort(int *arr, ssize_t N)
{
    ssize_t i;
    for(i = 2 ; i <= N ;i++)
    {
        insert_at_sorting_position(arr , i);
    }
}
