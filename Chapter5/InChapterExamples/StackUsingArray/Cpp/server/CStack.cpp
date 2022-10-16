#include<iostream>
#include "IStack.h"
#include<stdexcept>

class CStack : public IStack
{
    private:
        int* S;
        int capacity;
        int t;
    public:
        CStack (int _capacity = 10): capacity(_capacity)
        {
            S = new int[capacity];
            t = -1; 
        }

        virtual int size() const
        {
            return(t + 1);
        }

        virtual bool empty() const
        {
            return(t < 0);  
        }

        virtual const int& top() const
        {   
            if(empty()) throw std::runtime_error("Stack Empty");
            return S[t];
        }

        virtual void push(const int& e)
        {
            if(size() == capacity) throw std::runtime_error("Stack Full");
            S[++t] = e;

        }

        virtual void pop()
        {
            if(empty()) throw std::runtime_error("stack already Empty");
            --t;
        }


};

IStack* IStack::ReturnObject(int Capacity)
{
    return new CStack(Capacity);
}

