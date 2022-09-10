/*
R-3.8 Give a fully generic implementation of the doubly linked list data structure
of Section 3.3.3 by using a templated class.
R-3.9 Give a more robust implementation of the doubly linked list data structure of Section 3.3.3, which throws an appropriate exception if an illegal
operation is attempted.
*/
#ifndef _CLIST_H
#define _CLIST_H
class Node
{
    friend class CDoublyCircularLinkedList;
    private:
        int data;
        Node* next;
        Node* prev;

        Node(int iData);

};


class CDoublyCircularLinkedList
{
    private:
        Node* PHeadNode;
        static void GenericInsert(Node*  prev, Node* mid, Node* next);
        static void GenericDelete(Node* node);
        Node* searchNode(int data);
        bool is_empty() const;

    public:
        class Iterator ;
        CDoublyCircularLinkedList();
        ~CDoublyCircularLinkedList();
        //Copy contructor and = operator
        CDoublyCircularLinkedList(const CDoublyCircularLinkedList& other);
        CDoublyCircularLinkedList& operator =(const CDoublyCircularLinkedList& other);

        //List Routines
        void insert_start(int new_data);
        void insert_end(int new_data);
        void insert_after(int after_data, int new_data);
        int get_start();
        int get_end();
        int pop_start();
        int pop_end();
        
        //Iterator Routines
        Iterator begin();
        Iterator end();

        class Iterator
        {
            private:
                Node* p_node;
            public:
                Iterator(Node* p  = 0);

                void setNode(Node* p_new_node);
                int  operator *();
                bool operator !=(const Iterator& other);
                Iterator& operator ++();


        };

};


#endif