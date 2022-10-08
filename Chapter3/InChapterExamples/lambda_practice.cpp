#include<iostream>

//i) To Find Max of Two Integers

int main()
{
    //i) To Find Max of Two Integers
    int ret = [](int m,int n)->int{
        return (m > n ? m : n);
    }(20,25);

    std::cout<<"max is" <<ret<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;

    // ii)to Find min of two ints

    ret = [](int m , int n)-> int{
        return(m < n ? m : n);
    }(15,29);
    std::cout<<"min is" <<ret<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;

    //iii)Mean of Three Integers
    ret = [](int m , int n, int k)-> int{
        return((m+n+k) / 3 );
    }(12,32,12);
}
