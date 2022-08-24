#include<cstdio>
#include"Dlist.h"

int main()
{
    DLinkedList* p_list = new DLinkedList();
    p_list->ShowList();
    p_list->InsertStart(10);
    p_list->ShowList();
    for(int i = 0; i<5 ; i++)
	{
        p_list->InsertStart(i);
	}
    p_list->ShowList();

}