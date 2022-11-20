#include<iostream>

typedef struct contains_ptr
{
    int m;
    
}contains_ptr;

class Contains_ptr
{
    private:
        int n;
        contains_ptr* ptr;
    
    public:
        Contains_ptr(int _n, int _m): n(_n), ptr(new contains_ptr)
        {
            ptr->m = _m;
        }

        void printAddress() const
        {
            std::cout<< "ptr :" << ptr<<std::endl;        
        }

        void showM() const
        {
            std::cout<<"M:"<< ptr->m <<std::endl;
            std::cout<<"&M"<<&(ptr->m)<<std::endl;
        }

        void showN() const
        {
            std::cout<<"n"<< n <<std::endl;
            std::cout<<"&N"<<&n<<std::endl;
        }
        
        ~Contains_ptr()
        {
            delete ptr;
        }
};


int main()
{
    Contains_ptr C(10,20);
   // std::cout<< "C::ptr::m"<< C.showM()<<" "<<"C::n"<<C.showN() <<"C::ptr"<<C.printAddress()<<std::endl;
   C.printAddress();
   C.showM();
   C.showN();
   std::cout<<"---------------------------------"<<std::endl;
   Contains_ptr E(C);
   Contains_ptr D = C;
    D.printAddress();
    D.showM();
    D.showN();
    std::cout<<"---------------------------------"<<std::endl;
    E.printAddress();
    E.showM();
    E.showN();

}

//pointer is object is shared between Two object That is so when one Object is destroyed other other will have no access to its 
//member and segmentation fault will  be thrown.
//To avoid this we write copy contructor explicitely