
#include<iostream>

template<typename T>
class Node
{
    private:
        T data;
        Node* next;
    friend class SinglyLinkedList;

};

template<typename T>
class SinglyLinkedList
{
    private:
        Node<T>* HeadNode;
        static Node<T>* getNode();

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool isListEmpty();
        const int GetFront() const ;
        void AddFront(T);
        void RemoveFront();
        void showList();
        


};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    HeadNode = getNode();
    HeadNode ->next = NULL;
    HeadNode ->data = 0;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
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

template<typename T>
bool SinglyLinkedList<T>::isListEmpty()
{
    return(HeadNode->next == NULL);
}

template<typename T>
const int SinglyLinkedList<T>::GetFront() const
{ 
    return (HeadNode->next->data);
}

template<typename T>
void SinglyLinkedList<T>::AddFront(T data)
{
    Node* v = getNode();
    v->data = data;
    v->next = HeadNode->next;
    HeadNode->next = v;
}

template<typename T>
void SinglyLinkedList<T>::RemoveFront()
{
    Node* node = HeadNode->next;
    HeadNode->next = HeadNode->next->next;
    delete(node);
    node = NULL;
}

template<typename T>
void SinglyLinkedList<T>::showList()
{
    for(Node* node = HeadNode->next ; node->next != NULL ; node= node->next)
    {
        std::cout<<node->data<<"------";
        //if << not loaded for the data's datatype exception will occur
    }
    std::cout<<std::endl;
}

template<typename T>
Node<T>* SinglyLinkedList<T>::getNode()
{
    Node* node = new Node();
    node->data = 0;
    node->next = NULL;
    return node;
}


int main()
{
    SinglyLinkedList<int>* list = new SinglyLinkedList<int>();
    for(int i = 0; i < 5 ;i++)
    {
        list->AddFront(i);
    }

    list->showList();
    delete(list);
    
}






