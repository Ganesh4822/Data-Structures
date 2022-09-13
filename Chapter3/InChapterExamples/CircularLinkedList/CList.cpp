#include<cstdio>
#include "CList.hpp"


CNode* CicularList::getNode(int data)
{
    CNode* node = new CNode();
    node->data = data;
    node->next = NULL;
    return node;
}


CicularList::CicularList()
{
    cursor = NULL;

}

CicularList::~CicularList()
{
    while(!empty())
        remove();
}

bool CicularList::empty() const
{
    return(cursor == NULL);
}

//elemnt following cursor
const int CicularList::front() const
{
    return(cursor->next->data);
} 

//Element at cursor
const int CicularList::back() const
{
    return(cursor->data);
} 

void CicularList::advance()
{
    cursor = cursor->next;
}

//add after cursor
void CicularList::add(int data)
{
    CNode* node = getNode(data);
    if(empty())
    {
        node->next = node;
        cursor = node;
    }
    else{
        node->next = cursor->next;
        cursor->next = node;
    }
      
} 

//remove the element pointed by cursor
//Doubt in this function
void CicularList::remove()
{
    CNode* delete_node = cursor->next;
    if(cursor->next == cursor)
    {
        cursor == NULL;
    }
    else{
        cursor->next = delete_node;
    }
    
}