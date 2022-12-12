#pragma once

#include<iostream>


namespace myDsa
{

    class MapNode
    {
        
        friend class MyMap;
        private:
            std::string key;
            long  value;
            MapNode* next;
            MapNode* prev;
        public:
            MapNode(const std::string& _k , const long& _v):key(_k),value(_v){
                next = nullptr;
                prev = nullptr;
            }
    };

    
    class MyMap
    {
        private:
            MapNode* head;
            std::size_t size;
            static void GenericInsert(MapNode* f,MapNode* mid,MapNode* s)
            {
                mid->next = s;
                mid->prev = f;
                s->prev = mid;
                f->next = mid;
            }
            static void genericDelete(MapNode* deleteNode)
            {
                deleteNode->next->prev = deleteNode->prev;
                deleteNode->prev->next = deleteNode->next;
                delete(deleteNode);
                
            }

            MapNode* searchNode(std::string _key)
            {
                
                for(MapNode* node = head->next ; node != head ; node = node ->next )
                {
                    
                    if(!node->key.compare(_key))
                    {
                        return node;
                    }
                }
                return nullptr;
            }
            
        public:
            class Iterator;
            class Compare;
            MyMap()
            {
                head = new MapNode("head",0);
                head->next = head;
                head->prev = head;
                size = 0;
            }

            void put(std::string _key, long _value)
            {
                MapNode* newNode = new MapNode(_key,_value);
                GenericInsert(head,newNode,head->next);
                this->size++;
            }


            Iterator begin()
            {
                return Iterator(head->next);
            }

            Iterator end()
            {
                return Iterator(head);
            }

            class Iterator
            {
                private:
                    MapNode* p;
                public:
                    Iterator(MapNode* piNode):p(piNode){}

                    Iterator operator++()
                        {
                            p = p->next; 
                            return *this; 
                        }

                    Iterator operator--()
                    {
                        p = p->prev;
                        return *this;
                    }
                    
                    MapNode* operator*()
                    {
                        return p;

                    }

                    bool operator==(const Iterator& other)
                    {
                        //As compare returns 0 if strings are equal.
                        return !p->key.compare(other.p->key);
                    }

                    bool operator!=(const Iterator& other)
                    {
                        return p->key.compare(other.p->key);
                    }



            };

            long get(std::string _key)
            {
                for(Iterator Iter = begin() ; Iter != end(); ++Iter)
                {
                    if((*Iter)->key.compare(_key))
                    {
                        return (*Iter)->value;
                    }
                }   
                return 0;
            }

            void Remove(std::string _key)
            {
                MapNode * deleteNode = searchNode(_key);
                genericDelete(deleteNode);
                this->size--;
                deleteNode = nullptr;
            }

            bool empty()
            {
                if(head->next == head)
                    return true;
                return false;
            }

            void swap(MapNode* node1 , MapNode* node2)
            {
                MapNode* temp = new MapNode(node2->key, node2->value);
                node2->key = node1->key;
                node2->value = node1->value;

                node1->key = temp->key;
                node1->value = temp->value;
                delete(temp);
            }

            long operator[](std::string _key)
            {
                
                MapNode* node = searchNode(_key);
                
                return node->value;
            }

            int getSize()
            {
                return size;
            }

            void PrintMap()
            {
                if(head->next == nullptr)
                {
                    std::cout<<"Empty map"<<std::endl;
                    return;
                }
                
                for(Iterator Iter = begin() ; Iter != end() ; ++Iter)
                {
                    std::cout<<(*Iter)->key<<"::"<<(*Iter)->value<<"<->";
                }

                std::cout<<std::endl;
            }

            ~MyMap()
            {
                MapNode* p_next_node;
                for(MapNode* node = head->next ; node != head ;node = p_next_node)
                {
                    p_next_node = node->next;
                    delete(node);
                }
                delete(head);
            }

    };
}


//Implement functionality for Duplicate key
