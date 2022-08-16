#include<iostream>

class B1
{
    private:  
        int n;
    public:
        B1(int _n = 0):n(_n)
        {

        }

        int get_n()
        {
            return n;
        }
};

class B2
{
    private:  
        int n;
    public:
        B2(int _n = 0):n(_n)
        {

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
        D( int _n2, int _n3):B1(_n2),B2(_n3)
        {

        }

    //     int get_n()
    //     {
    //         return n;
    //     }
};

int main()
{
    D objD(20,30);

    //std::cout<<"ObjD.get_n() :: "<<objD.get_n()<<std::endl;
    //inline int B1::get_n()
//ERROR :: "D::get_n" is ambiguous

}

