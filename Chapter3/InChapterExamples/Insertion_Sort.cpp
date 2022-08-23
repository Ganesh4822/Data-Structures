#include<iostream>

template <typename T>
void insertion_sort(T* arr, int n)
{
    int i,j;
    T current;
    for ( i = 1; i<n ; i++)
    {
        current = arr[i];
        j = i -1;
        while((j >= 0) && (arr[j] > current))
        {
            arr[j + 1]  = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    
}

template<typename T>
void print(T* arr, int n)
{
    for(int i = 0; i< n; i++)
    {
        std::cout<<arr[i] << " ";
    }
    std::cout<<std::endl;
    
}


int main()
{
    int a[5] = {4,63,1,43,2};
    double b[5] = {2.21323,.1231,2.2032,6,2.26080};
    char c[5] = {'s','t','c','e','t'};
    std::cout<<"Before"<<std::endl;
    print<int>(a,5);
    print<double>(b,5);
    print<char>(c,5);

    insertion_sort<int>(a,5);
    insertion_sort<double>(b,5);
    insertion_sort<char>(c,5);

    std::cout<<"After"<<std::endl;
    print<int>(a,5);
    print<double>(b,5);
    print<char>(c,5);

 
}
