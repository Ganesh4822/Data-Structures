#include<cstdio>
#include<iostream>
#include"Dlist.h"

int main()
{
    DLinkedList* p_list = new DLinkedList();
    p_list->ShowList();
    std::cout<<std::endl;
    p_list->InsertStart(10);
    p_list->ShowList();
    std::cout<<std::endl;
    for(int i = 1; i<6 ; i++)
	{
        p_list->InsertStart(i);
	}

    p_list->ShowList();
    std::cout<<std::endl;
    p_list->PopStart();
    p_list->PopEnd();

    p_list->ShowList();
    std::cout<<std::endl;
    p_list->AddAfter(30,3);
    p_list->ShowList();

    delete(p_list);
    p_list = NULL;

}