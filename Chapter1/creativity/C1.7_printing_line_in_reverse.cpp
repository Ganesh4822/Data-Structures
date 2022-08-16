/*Write a short C++ program that takes all the lines input to standard input
and writes them to standard output in reverse order. That is, each line is
output in the correct order, but the ordering of the lines is reversed.
*/
#include<iostream>
#include<vector>
#include<string>

int main(void)
{
    std::vector <std::string> stack;
    int c;
    while((c = getchar())!= EOF)
    {
        std::string line;
        do
        {
            if(std::cin.eof())
                break;
            line.push_back(c);
        }while(c != '\n');
        stack.push_back(line);

    }

    while (!stack.empty())
    {
        std::cout<<stack.back();
        stack.pop_back();



    }



}