#include<stdio.h>
#include<stdlib.h>

typedef long long ssize_t;
typedef int (*COMPARE)(void*,void*);

typedef struct Employee
{
    long EmployeeCode;
    char name[32];
    unsigned int age;
}employee;

int compareEmployee(employee* emp1, employee* emp2)
{
    return(emp1->EmployeeCode >= emp2->EmployeeCode ? 1 : 0);
}

void InsertionSort(void* arr, ssize_t N , ssize_t mem_size , COMPARE compare)
{
    ssize_t i,j;
    void* key ;
    key = malloc(mem_size);
    memset(key,0,mem_size);
    for(i = 2 ; i <= N ; i++)
    {
         memcpy(key,(char*)arr + (i-1)*mem_size,mem_size);
         j = i-2;
         while( j > -1 && compare(((char*)arr + (j + 1) * mem_size),key) )
         {
            memcpy(((char*)arr + (j + 1)* mem_size) , ((char*)arr + (j)* mem_size) ,mem_size);
            j = j -1;
         }

         memcpy((char*)arr + (j+1) * mem_size , key, mem_size);
        
    }

    free(key);
    key = NULL;
}

void show_employee_array(employee* pa, ssize_t N, const char* msg)
{
    ssize_t i; 

    if(msg)
        puts(msg); 

    for(i=0; i<N; ++i)
    {
        printf("EmployeeNo #%lld\n", i+1); 
        printf("EmployeeCode:%d\n", pa[i].EmployeeCode); 
        printf("Name:%s\n", pa[i].name); 
        printf("Age:%u\n", pa[i].age); 
        puts("-----------"); 
    }
    puts("---------------------------------"); 
}

employee s_arr[5] = {
    {211, "A", 32}, 
    {10, "M", 98}, 
    {7, "N", 65}, 
    {3, "B", 24}, 
    {2, "Q", 30}
}; 

int main(void)
{
    show_employee_array(s_arr, 5, "Before sorting:"); 
    InsertionSort(s_arr, 5, sizeof(employee),compareEmployee ); 
    show_employee_array(s_arr, 5, "Sorted according to roll number:"); 
    // generic_insertion_sort(s_arr, 5, sizeof(struct student), compareEmployee);
    // show_student_array(s_arr, 5, "Sorted according to marks:"); 
    // generic_insertion_sort(s_arr, 5, sizeof(struct student), compare_with_attnd);
    // show_student_array(s_arr, 5, "Sorted according to attendance:"); 
    return (EXIT_SUCCESS); 
}   

