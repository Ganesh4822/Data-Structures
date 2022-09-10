#include<iostream>
#include "ClistException.h"
#include "CList.hpp"

// Node contructor

Node::Node(int idata)
{
    data = idata;
    next = 0;
    prev = 0;
}

//CDoublyCircularLinkedList contrcutor
CDoublyCircularLinkedList::CDoublyCircularLinkedList()
{
    PHeadNode = new Node(0);
    PHeadNode->next = PHeadNode;
    PHeadNode->prev = PHeadNode;
}

//CDoublyCircularLinkedList destructor
CDoublyCircularLinkedList::~CDoublyCircularLinkedList()
{
    Node *current,*pNode;
    for(current = PHeadNode->next ; current != PHeadNode ; current = pNode)
    {
        pNode = current->next;
        delete(current);
    }

    delete(PHeadNode);
    PHeadNode = NULL;
}

//copy contructor
CDoublyCircularLinkedList::CDoublyCircularLinkedList(const CDoublyCircularLinkedList& other)
{
    throw std::runtime_error("cannot initialize list with other list");
}

//Assignment operator overload
CDoublyCircularLinkedList& CDoublyCircularLinkedList::operator =(const CDoublyCircularLinkedList& other)
{
    throw std::runtime_error("cannot initialize list with other list");
}

//Static private Routines
void CDoublyCircularLinkedList::GenericInsert(Node*  _prev, Node* mid, Node* _next)
{
    mid->next  = _next;
    mid->prev = _prev;
    _prev->next = mid;
    _next->prev = mid;
}

void CDoublyCircularLinkedList::GenericDelete(Node* node)
{
    node->prev->next = node->next;
    node->next->prev= node->prev;
    delete(node);
    node = 0;
}

Node* CDoublyCircularLinkedList::searchNode(int data)
{
    Node* pNode;
    for(pNode = this->PHeadNode->next ; pNode != this->PHeadNode ; pNode = pNode->next)
    {
        if(pNode->data == data)
        {
            return pNode;
        }
    }
    return 0;
}

bool CDoublyCircularLinkedList::is_empty() const 
{
    return PHeadNode->prev == PHeadNode && PHeadNode->next == PHeadNode; 
}

//List Routines
void CDoublyCircularLinkedList::insert_start(int new_data)
{
    GenericInsert(PHeadNode,new Node(new_data),PHeadNode->next);
}

void CDoublyCircularLinkedList::insert_end(int new_data)
{
    GenericInsert(PHeadNode->prev,new Node(new_data),PHeadNode);
}

void CDoublyCircularLinkedList::insert_after(int after_data, int new_data)
{
    Node* node = searchNode(after_data);
    if(!node)
        throw CListDataNotFound("insert After : Bad Data");
    GenericInsert(node,new Node(new_data),node->next);
}

int CDoublyCircularLinkedList::get_start()
{
    if(is_empty())
        throw CListEmpty("getStart on empty list");
    return this->PHeadNode->next->data;
}

int CDoublyCircularLinkedList::get_end()
{
    if(is_empty())
        throw CListEmpty("getend on empty list");
    return this->PHeadNode->prev->data;
}

int CDoublyCircularLinkedList::pop_start()
{
    if(is_empty())
        throw CListEmpty("popStart on empty list");
    int Pdata = this->PHeadNode->next->data;
    GenericDelete(this->PHeadNode->next);
    return Pdata;
}

int CDoublyCircularLinkedList::pop_end()
{
    if(is_empty())
        throw CListEmpty("popend on empty list");
    int Pdata = this->PHeadNode->prev->data;
    GenericDelete(this->PHeadNode->prev);
    return Pdata;
}


//Iterator Routines
CDoublyCircularLinkedList::Iterator CDoublyCircularLinkedList::begin()
{
   return Iterator(PHeadNode->next);
}

CDoublyCircularLinkedList::Iterator CDoublyCircularLinkedList::end()
{
    return Iterator(PHeadNode);
}

//Iterator contructor
CDoublyCircularLinkedList::Iterator::Iterator(Node* p): p_node(p)
{

}

//Iterator Routines

void CDoublyCircularLinkedList::Iterator::setNode(Node* p_new_node)
{
    p_node = p_new_node;
}

int  CDoublyCircularLinkedList::Iterator::operator *()
{
    return p_node->data;
}

bool CDoublyCircularLinkedList::Iterator::operator !=(const Iterator& other)
{
    return(p_node != other.p_node);
}

CDoublyCircularLinkedList::Iterator& CDoublyCircularLinkedList::Iterator::operator ++()
{
    p_node = p_node->next;
    return *this;
}