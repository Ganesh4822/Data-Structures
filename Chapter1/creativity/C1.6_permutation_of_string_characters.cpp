#include<iostream>
#include<list>
#include<string>
#include<cstdlib>


std::ostream& operator<<(std::ostream& out, const std::list<char> &L)
{
    std::list<char>::const_iterator p = L.begin();
    while(p != L.end())
    {
        out<<*p;
        p++;       
    }
    return out;
}

void permute(std::list<char>& bag, std::list<char>&permutation)
{
    if(bag.empty())
        std::cout<<permutation<<std::endl;
    else{
        std::list<char>::iterator p = bag.begin();
        while(p != bag.end())
        {
            std::list<char>::iterator n = p;
            n++;
            char c = *p;
            permutation.push_back(c);
            permute(bag,permutation);
            permutation.pop_back();
            bag.insert(n,c);
            p++;
        }
    }
}


void printPermutation(std::list<char>& elements)
{
    std::list<char> bag = elements;
    std::list<char> permutation;
    permute(bag,permutation);
    std::cout<<permutation<<std::endl;
}



int main()
{
    const char elts[] = {'a','b','c','d','e','f'};
    std::list<char> elements;
    for(int i = 0; i< 6 ; i++)
    {
        elements.push_back(elts[i]);
    }
    printPermutation(elements);


}