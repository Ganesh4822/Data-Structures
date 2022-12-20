#include<iostream>

template<typename T>
void insertion_sort(T* a, size_t N)
{
    int i, j;
    T key; 

    for(j = 1; j < N; ++j)
    {
        key = a[j]; 
        i = j - 1; 
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i]; 
            i = i - 1; 
        }
        a[i+1] = key; 
    }
}

template<typename T>
void show(T* a, size_t N, const char* msg)
{
    int i; 

    if(msg)
        puts(msg); 
    
    for(i = 0; i < N; ++i)
        std::cout<<a[i]<<std::endl; 
}


int main()
{
    int a[10]  = {1,7,4,78,23,45,2,67,11,9};
    show<int>(a,10,"array before Sorting");

    insertion_sort<int>(a,10);

    show<int>(a,10,"Array afte sorting");

    double d[] = {23.56,2.454,67.34223,1.3242343,674.232131,674.1233212};
    int size = sizeof(d)/sizeof(double);

    show<double>(d,size,"double array before sorting");
    insertion_sort<double>(d,size);
    show<double>(d,size,"double array after sorting");

    
}