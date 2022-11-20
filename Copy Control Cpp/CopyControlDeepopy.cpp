#include<iostream>

typedef struct containsptr
{
    int m;
}hasptr;

class Contains_ptr
{
    private:
        int n;
        hasptr* ptr;
    
    public:
        Contains_ptr(int _n, int _m): n(_n), ptr(new hasptr)
        {
            ptr->m = _m;
        }

        Contains_ptr(const Contains_ptr& other)
        {
            hasptr* newptr = new hasptr;
            newptr->m = other.ptr->m;
            this->ptr = newptr;
            this->n = other.n;
        }

        Contains_ptr& operator=(const Contains_ptr& otherobj)
        {
            hasptr* newptr = new hasptr;
            newptr->m = otherobj.ptr->m;
            this->ptr =newptr;
            this->n = otherobj.n; 
            return *this;
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