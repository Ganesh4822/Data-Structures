#include<iostream>

long getGCD(long m, long n);

int main()
{
    std::cout<<"GCD is "<<getGCD(80844,25320)<<std::endl;
}


long getGCD(long m, long n)
{
    long divisor = n;
    long dividend = m;

    long remainder ;
    while (remainder != 0)
    {   
        remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;

    }

    return dividend;
}