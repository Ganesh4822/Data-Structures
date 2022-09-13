#include<iostream>
#include "ClistException.h"

template <typename T>
class Node
{
    private:
        T data;
        Node<T>* next;
        Node(T data)
        {
            this->data = data;
            this->next = 0;
        }
    
    template <typename T>
    friend class CircularList;
        
};


template <typename T>
class CircularList
{
    
    private:
        Node<T> curser;

    public:
        template <typename T>
        class Iterator;
        CircularList<T>()
        {
            curser = NULL;
        }

        ~CircularList<T>()
        {
            if(!empty())
            {
                remove();
            }
        }

        bool empty() const
        {
            return(curser == NULL);
        }

        const T front() const
        {
            return(curser->next->data);
        }

        const T back() const
        {
            return(curser->data);
        }

        void Advance() {
            curser = curser -> next;
        }

        void add(T data)
        {
            Node<T>* newNode = new Node<T>(data);
            if(empty())
            {
                newNode ->next = newNode;
                curser = newNode;
            }
            else{
                newNode->next = curser->next;
                curser->next = newNode;
            }
            
        }

        //remove the Element followed by curser
        void remove()
        {
            if(empty())
            {
                throw CListEmpty("Cannot Apply remove on empty list");
            }
            Node<T>* node = curser->next;
            if(curser->next == curser)
            {
                delete(curser);
                return;
            }
            else
            {
                curser->next = node->next;
                delete(node);
                return;
            }
            
        }

        // void show() const
        // {
        //     Node<T>* node;
        //     for(node =  curser->next; node!= curser ; node = node->next)
        //     {
        //         std::cout<<node->data<<"------";
        //     }
        //     std::cout<<std::endl;
        // }
        Iterator<T> begin()
        {
            return Iterator<T>(curser->next); 
        }

        Iterator<T> end()
        {
            return Iterator<T>(curser);
        }
        template<typename T>
        class Iterator
        {
            private:
                Node<T>* pNode;

            public:

            Iterator<T>(Node<T>* p)
            {
                pNode = p;
            }
            T operator*()
            {
                return (pNode->data);
            }

            bool operator!=(Iterator& other)
            {
                return(this->pNode  != other.pNode);
            }

            void setNode(Node<T>* node)
            {
                pNode = node;
            }

            Iterator<int>& operator++()
            {
                this->pNode = pNode->next;
                return *this;
            }


        };

};


int main()
{
    CircularList<int> List;
    for(int i = 0; i < 5 ; i++)

    {
        List.add(i);

    }

    for(CircularList<int>::Iterator<int> iter = List.begin() ; iter != List.end(); ++iter )
    {
        std::cout<<*iter<<"---";
    }
    
}
