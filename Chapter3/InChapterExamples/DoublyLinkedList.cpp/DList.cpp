#include<iostream>
#include<cstdio>
#include "DList.h"
//ERRORS in THE IMPLEMENTATION
//IMPLEMNT ALL METHODS CONSIDERING TAIL NODE.

//Defination of Helper Routines
void DLinkedList::AddNode(DNode* start, DNode* nodeToAdd, DNode* end)
{
    start->next = nodeToAdd;
    end->prev = nodeToAdd;
    nodeToAdd->next = end;
    nodeToAdd->prev = start;
}

void DLinkedList::RemoveNode(DNode* NodeToRemove)
{
    NodeToRemove->prev->next = NodeToRemove->next;
    NodeToRemove->next->prev = NodeToRemove->prev;

    delete(NodeToRemove);
}

DNode* DLinkedList::getNode(int _data)
{
    DNode* node = new DNode();
    node->data = _data;
    node->next = NULL;
    node->prev = NULL;
    return(node);
}

DNode* DLinkedList::searchNode(int sData)
{
    DNode* node;
    for(node = head->next; node->next != NULL; node = node->next)
    {
        if(node->data == sData)
        {
            return node;
        }
    }

    return NULL;
    
}


//service Ruitines

 DLinkedList::DLinkedList()
 {
    head  = getNode(0);
    tail = getNode(0);
     head->next = tail;
     tail->prev = head;
    // head->prev = NULL;
 }

DLinkedList::~DLinkedList()
{
    DNode* node;
    DNode* temp;
    node = head->next;
    while(node->next != NULL)
    {
        temp = node;
        delete(node);
        node = temp->next;
    }
    delete(head);

}

bool DLinkedList::isempty()
{
    return(head->next == NULL);
}

const int DLinkedList::GetFront() const
{
    return(head->next->data);
}


const int DLinkedList::GetBack() const
{
    DNode* node = head->next;
    while(node->next != NULL){
        node = node->next;
    }
    return(node->data);
}

void DLinkedList::InsertStart(int data)
{
    DNode* node = getNode(data);
    if(node == NULL)
    {
        std::cerr<<"Node not allocated"<<std::endl;
    }
    AddNode(head,node,head->next);
}


void DLinkedList::InsertEnd(int data)
{
    DNode* node = getNode(data);
    DNode* temp = head->next;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;

}

int DLinkedList::PopStart()
{
    int Pdata = head->next->data;
    RemoveNode(head->next);
    return Pdata;
}

int DLinkedList::PopEnd()
{
    DNode* temp = head->next;
    while(temp->next != NULL){
        temp = temp->next;
    }
    int Pdata = temp->data;
    RemoveNode(temp);
    return Pdata;
}
// void AddAfter(int newData,int afterData);
void DLinkedList::ShowList() const
{
    
	printf("[START<->]");
	for(DNode* p_run = this->head->next;
		p_run != NULL;
		p_run  = p_run->next)
		printf("[%d]<->",p_run->data);
	printf("[END]");

}