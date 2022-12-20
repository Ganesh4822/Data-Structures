/*
C-2.1 Give an example of a C++ program that outputs its source code when it is
run. Such a program is called a quine.
*/

#include<stdio.h>
int main()
{
    const char* s = "#include<stdio.h%cint main(void)%c{%cconst char* s = %c%s%c;%cprintf(s,10,34,s,10,34)%c}";
    printf(s,10,10,10,34,s,10,34,10);
}