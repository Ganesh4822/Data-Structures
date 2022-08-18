/*
C-2.7 Write a program that consists of three classes, A, B, and C, such that B is a
subclass of A and C is a subclass of B. Each class should define a member
variable named “x” (that is, each has its own variable named x). Describe
a way for a member function in C to access and set A’s version of x to a
given value, without changing B or C’s version.
*/

#include<iostream>

class A 
{
    private:
        int x;
    public:
        A(int _x = 0):x(_x){}
        void set_x(int new_x)
        {
            x = new_x;

        }

        int get_x()
        {
            return x;
        }


        

};

class B: public A 
{
    private:
        int x;
    public:
        B(int _x = 0):x(_x){}

};

class C : public B
{
    private:
        int x;
    public:
        C(int _x):x(_x){}
        
        void set_x(int new_x)
        {
            x = new_x;
        }

         int get_x()
        {
            return x;
        }


};


int main()
{
    C* a = new C(10);
    //sizeof(*a) = 12 bytes hence all the 3 x are incorporated in this object.
 
    std::cout<<sizeof(*a)<<std::endl;
    //a->set_x(10);
    a->set_x(30);//Class c's set x will be called
    static_cast<A*>(a)->set_x(10);//Class A's set x will be called
    std::cout<<static_cast<A*>(a)->get_x()<<std::endl;
    delete(a);
    a = NULL;

}