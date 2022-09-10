#include<iostream>
#include "CList.hpp"

int main(void)
{
    CDoublyCircularLinkedList L; 

    for(int i = 0; i != 100; i += 10)
        L.insert_end(i); 

    for(CDoublyCircularLinkedList::Iterator iter = L.begin(); iter != L.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl; 
    std::cout<<"SuCCESS"<<std::endl;
    L.insert_after(40,10000);

    for(CDoublyCircularLinkedList::Iterator iter = L.begin(); iter != L.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl;

    std::cout<<L.pop_end()<<std::endl;

    for(CDoublyCircularLinkedList::Iterator iter = L.begin(); iter != L.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl;

    std::cout<<L.pop_start()<<std::endl;

    return 0;
}