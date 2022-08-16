#include<iostream>


class B
{
    private:  
        int n;
    public:
        B()
        {
            puts("int B :: default contructor");
        }

        // int get_n()
        // {
        //     return n;
        // }
};

class B1 : public B
{
    private:  
        int n;
    public:
        B1()
        {
            puts("int B1 :: default contructor");
        }

        // int get_n()
        // {
        //     return n;
        // }
};

class B2 : public B
{
    private:  
        int n;
    public:
        B2()
        {
            puts("int B2 :: default contructor");
        }

        int get_n()
        {
            return n;
        }
};

class D :public B1, public B2
{
    // private:  
    //     int n;
    public:
        D()
        {
            puts("int D :: default contructor");
        }

    //     int get_n()
    //     {
    //         return n;
    //     }
};

int main()
{
    D objD;

    //std::cout<<"ObjD.get_n() :: "<<objD.get_n()<<std::endl;
    //inline int B1::get_n()
//ERROR :: "D::get_n" is ambiguous

}

