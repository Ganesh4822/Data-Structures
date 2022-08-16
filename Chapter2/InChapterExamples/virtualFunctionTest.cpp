#include<iostream>

class Base
{
    private:
        int a,b;
    public:
        
        Base(int _a = 0, int _b = 0):a(_a),b(_b)
        {
             std::cout<<"inside Base class parameterized contructor"<<std::endl;
        }

        virtual void func1()
        {
            std::cout<<"inside Base::fun1()"<<std::endl;
        }
};


class Derived1 : public Base{
    private:
        int c, d;
    public:
        Derived1(int _c, int _d):Base(),c(_c),d(_d)
        {
            std::cout<<"inside Derived one Parameterized contructor"<<std::endl;
        }

        virtual void func1()
        {
            std::cout<<"inside Derived::fun1()"<<std::endl;
        }
};



class Derived2 : public Base{
    private:
        int e, f;
    public:
        Derived2(int _e, int _f):Base(),e(_e),f(_f)
        {
            std::cout<<"inside Derived2 Parameterized contructor"<<std::endl;
        }

        virtual void func1()
        {
            std::cout<<"inside Derived2::fun1()"<<std::endl;
        }
};



int main()
{
    Base* b = new Derived1(2,4);
    reinterpret_cast<Derived2*>(b)->func1();

}