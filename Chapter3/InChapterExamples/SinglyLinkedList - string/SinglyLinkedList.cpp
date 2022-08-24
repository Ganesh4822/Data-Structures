
#include<iostream>

class Node
{
    private:
        int data;
        Node* next;
    friend class SinglyLinkedList;

};

class SinglyLinkedList
{
    private:
        Node* HeadNode;
        static Node* getNode();

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool isListEmpty();
        const int GetFront() const ;
        void AddFront(int);
        void RemoveFront();
        void showList();
        


};

SinglyLinkedList::SinglyLinkedList()
{
    HeadNode = getNode();
    HeadNode ->next = NULL;
    HeadNode ->data = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    Node* temp;
    Node* node;
    node = HeadNode->next;
    while(node != NULL)
    {
        temp = node;
        delete(node);
        node = temp->next;
    }
    delete(HeadNode);
}

bool SinglyLinkedList::isListEmpty()
{
    return(HeadNode->next == NULL);
}

const int SinglyLinkedList::GetFront() const
{ 
    return (HeadNode->next->data);
}

void SinglyLinkedList::AddFront(int data)
{
    Node* v = getNode();
    v->data = data;
    v->next = HeadNode->next;
    HeadNode->next = v;
}

void SinglyLinkedList::RemoveFront()
{
    Node* node = HeadNode->next;
    HeadNode->next = HeadNode->next->next;
    delete(node);
    node = NULL;
    
}

void SinglyLinkedList::showList()
{
    for(Node* node = HeadNode->next ; node->next != NULL ; node= node->next)
    {
        std::cout<<node->data<<"------";
    }
    std::cout<<std::endl;
}

Node* SinglyLinkedList::getNode()
{
    Node* node = new Node();
    node->data = 0;
    node->next = NULL;
    return node;
}


int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();
    for(int i = 0; i < 5 ;i++)
    {
        list->AddFront(i);
    }

    list->showList();
    delete(list);
    
}






