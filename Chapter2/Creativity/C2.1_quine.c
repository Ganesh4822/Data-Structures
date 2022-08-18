/*
C-2.1 Give an example of a C++ program that outputs its source code when it is
run. Such a program is called a quine.
*/

#include<stdio.h>
main(void)
{const char* s =  "#include<stdio.h>%cmain(void) {const char* s = %c%s%c;%cprintf(s,10,34,s,34,10);}";
printf(s,10,34,s,34,10);}
