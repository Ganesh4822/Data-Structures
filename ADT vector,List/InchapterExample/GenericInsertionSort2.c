#include<stdio.h>
#include<stdlib.h>

typedef int (*COMPARE)(void*,void*);
typedef long long ssize_t;
typedef struct student
{
    int marks;
    char* Name;
    int iD;
}student;

int compareStudent(student* s1, student* s2)
{
    return (s1->marks >= s2->marks ? 1 : 0);
}

void InsertionSort(void* arr , ssize_t N,COMPARE compare , ssize_t mem_size)
{
    ssize_t i,j;

    void*  key;

    key = malloc(mem_size);
    memset(key,0,mem_size);

    for(i = 2 ; i <= N ;i++)
    {
        memcpy(key,(char*)arr + (i-1)*mem_size ,mem_size);
        j = i-2;
        while(j > -1 && compare(((char*)arr + (j + 1) * mem_size),key))
        {
            memcpy((char*)arr + (j +1)*mem_size,(char*)arr + (j)*mem_size,mem_size);
            j--;
        }

        memcpy((char*)arr + (j +1)*mem_size, key,mem_size);
    }

    free(key);
    key =NULL;
}

void show_student_array(student* pa, ssize_t N, const char* msg)
{
    ssize_t i; 

    if(msg)
        puts(msg); 

    for(i=0; i<N; ++i)
    {
        printf(" #%lld\n", i+1); 
        printf("marks:%d\n", pa[i].marks); 
        printf("Name:%s\n", pa[i].Name); 
        printf("ID:%u\n", pa[i].iD); 
        puts("-----------"); 
    }
    puts("---------------------------------"); 
}

student s_arr[5] = {
    {56, "A", 32}, 
    {21, "M", 98}, 
    {7, "N", 65}, 
    {3, "B", 24}, 
    {2, "Q", 30}
};

int main(void)
{
    show_student_array(s_arr, 5, "Before sorting:"); 
    InsertionSort(s_arr, 5,(COMPARE)compareStudent, sizeof(student) ); 
    show_student_array(s_arr, 5, "Sorted according to roll number:"); 
    // generic_insertion_sort(s_arr, 5, sizeof(struct student), compareEmployee);
    // show_student_array(s_arr, 5, "Sorted according to marks:"); 
    // generic_insertion_sort(s_arr, 5, sizeof(struct student), compare_with_attnd);
    // show_student_array(s_arr, 5, "Sorted according to attendance:"); 
    return (EXIT_SUCCESS); 
}   
