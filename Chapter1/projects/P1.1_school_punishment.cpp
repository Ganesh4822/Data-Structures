#include<iostream>
#include<string>

int get_random_number();
std::string get_random_string(int n);

int main()
{
    int i = 0;
    while(i < 100)
    {
        std::cout<<get_random_string(get_random_number())<<std::endl;
        i++;
    }

}


int get_random_number()
{
    return(rand() % 8);

}

std::string get_random_string(int num)
{
    switch (num)
    {
    case 0:
        return("I will always not use object oriented design");
        break;
    case 1:
        return("I will always wwde object oriented design");
        break;
    case 2:
        return("I will alwasy use object oriented design");
        break;
    case 3:
        return("I will awlays use object oriented design");
        break;
    case 4:
        return("I wll always use object oriented design");
        break;
    case 5:
        return("I will always use objec oriented design");
        break;
    case 6:
        return("I will always use object orientd design");
        break;
    case 7:
        return("I will always use object oriented dsign");
        break;
    default:
        break;
    }
}
