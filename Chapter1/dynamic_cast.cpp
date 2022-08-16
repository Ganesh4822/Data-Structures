#include<iostream>
#include<cstdlib>


class Base
{
    public:
    Base()
    {
        puts("Inside base class contrctor");
    }
    virtual void f()
    {
     
            puts("In Base::f()"); 
    
    }
};

class D1 : public Base
{
    public:
    D1(){}
    virtual void f()
    {
        puts("inside D1:f1()");
    }

    void g1()
    {
        puts("inside D1 : g1()");
    }

};

class D2 : public Base
{
    public:
    D2(){}
     virtual void f()
    {
        puts("inside D2:f1()");
    }

    void g2()
    {
        puts("inside D2 : g2()");
    }

};

class D3 : public Base
{
    public:
    D3(){}
    virtual void f()
    {
        puts("inside D3:f1()");
    }

    void g3()
    {
        puts("inside D3 : g3()");
    }

};


Base* get_object(int rand)
{
    if(rand  == 0)
    {
        return new D1;
    }
    else if(rand  == 1)
    {
        return new D2;
    }
    else if(rand  == 2)
    {
        return new D3;
    }

    return NULL;
}


int main()
{
    srand( time(NULL) );
    int  randn = rand() % 3;
    Base* pb = get_object(randn);
    pb -> f();
    if(randn == 0)
    {
        dynamic_cast<D1*>(pb) ->g1();
    }
    else if(randn == 1)
    {
        dynamic_cast<D2*>(pb) ->g2();
    }
    else if(randn == 2)
    {
        dynamic_cast<D3*>(pb) ->g3();
    }
}