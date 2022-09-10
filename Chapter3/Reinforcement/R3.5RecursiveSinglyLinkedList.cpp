/*R-3.5 Give a recursive definition of a singly linked list.
R-3.6 Add a function size() to our C++ implementation of a singly link list. Can
you design this function so that it runs in O(1) time?
R-3.7 Give an algorithm for finding the penultimate (second to last) node in a
singly linked list where the last element is indicated by a null next link.
*/


#include<iostream>

class Node
{
    private: 
        int data;
        Node* next ;
    friend class SinglyLinkedList;  
};

class SinglyLinkedList
{
    private:
      Node* head;
      static Node* getNode(int data);
    
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool isListEmpty();
        const Node* GetFront() const ;
        void AddFront(int);
        void RemoveFront();
        void showList(const Node*);
        int getLast(const Node* current);
        int lpenultimate(const Node* current);
        void size(const Node*,int*);
       

};

Node* SinglyLinkedList::getNode(int _data)
{
    Node* node = new Node();
    node->data = _data;
    node->next = NULL;
    return node;

}

SinglyLinkedList::SinglyLinkedList()
{
    head = getNode(-1);
    head->next = NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{
    Node* node = head->next;
    Node* temp;
    while(node->next != NULL)
    {
        temp = node->next;
        delete(node);
        node = temp;
    }

    delete(head);
    head = NULL;
}



bool SinglyLinkedList::isListEmpty()
{
    if(head ->next == NULL)
        return true;
    else 
        return false;
}
const Node* SinglyLinkedList::GetFront() const
{
    return(head->next);
}

void SinglyLinkedList::AddFront(int data)
{
    Node* v = getNode(data);
    v->next = head->next;
    head->next = v;
}

void SinglyLinkedList::RemoveFront()
{
    Node* node = head->next;
    head->next = head->next->next;
    delete(node);
    node = NULL;
}

void SinglyLinkedList::showList(const Node* node)
{
    //Recursive
    if((node->next)!= NULL)
    {
        std::cout<<node->data<<"----------";
        showList(node->next);
    }
    else
    {
        std::cout<<node->data;
    }
    std::cout<<std::endl;
}

int SinglyLinkedList::getLast(const Node* current)
{
    //Recursive
    if((current->next != NULL))
    {
        getLast(current->next);
    }
    else
    {
        return current->data;
    }
    
}

int SinglyLinkedList::lpenultimate(const Node* current)
{
    if(current->next->next != NULL)
    {
        lpenultimate(current->next);
    }
    else
    {
        return current->data;
    }
    
}


void SinglyLinkedList::size(const Node* current,int* count )
{
    
    if(current -> next != NULL)
    {
        (*count)++;
        size(current->next,count);
    }
    else
    {
        (*count)++;
    }
    
}



int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();
    int count = 0;
    
    for(int i = 0; i < 5 ;i++)
    {
        list->AddFront(i);
    }

    list->showList(list->GetFront());
    list->RemoveFront();
    list->showList(list->GetFront());
    std::cout<<list->getLast(list->GetFront())<<std::endl;
    std::cout<<list->lpenultimate(list->GetFront())<<std::endl;
    list->size(list->GetFront(),&count);
    std::cout<<count<<std::endl;
    delete(list);
    
}

