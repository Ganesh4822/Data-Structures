/*
C-2.3 Most modern C++ compilers have optimizers that can detect simple cases
when it is logically impossible for certain statements in a program to ever
be executed. In such cases, the compiler warns the programmer about the
useless code. Write a short C++ function that contains code for which it
is provably impossible for that code to ever be executed, but your favorite
C++ compiler does not detect this fact.
*/

#include<iostream>
int function_that_contains_useless_code(void);
int main()
{
    int a = function_that_contains_useless_code();
    std::cout<<"Output of the function is "<<a<<std::endl;

}


int function_that_contains_useless_code(void)
{
    return 0;
    std::cout<<"control flow here"<<std::endl;


}