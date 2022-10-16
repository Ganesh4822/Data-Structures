#include<stdexcept>
//Struct of 5 function pointers will be formed.
class IStack
{
    public:
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual const int& top() const  = 0;
        virtual void push(const int& e) = 0;
        virtual void pop() = 0;
        static IStack* ReturnObject(int);
};