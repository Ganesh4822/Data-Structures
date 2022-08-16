/* 
    Use cases of static casts: 
        1)  If you want to make implicit type casts explicit 
            Type castings related built data types 
        2)  To code type conversions in C++ that implicitly 
            allowed by C but not by C++. 
            e.g. void* -> T* 
        3)  Base pointer to derived pointer conversion but 
            WITHOUT run time check of its validity 
            (here dynamic cast is more safe)
        What is not allowed under static_cast
        1)  Arbitrary type casting 
            cast expr of any type in any other time when 
            custom data types (classes) are involved. 
            This is a forte of reinterpret_cast 
*/ 

#include <cstdio> 
#include <cstdlib>
#include<iostream> 

void static_cast_use_cases_1(void); 
void static_cast_use_cases_2(void); 
void static_cast_use_cases_3(void); 

int main(void) 
{
    static_cast_use_cases_1(); 
    static_cast_use_cases_2(); 
    static_cast_use_cases_3(); 

    return (0); 
}

void static_cast_use_cases_1(void)
{
    int n = 0xa0b0c0d0; 
    char c = 'A'; 
    short s = 0xf0f0; 
    float f = 3.14f; 
    double d = 56345.3635; 

    s = c;  // implicit type casting will cast 
            // c into short 
    s = static_cast<short>(c);  // Make it explicit 

    c = n;  //  Compiler will do implicit type casting 
            //  from into to char, but probably will raise 
            //  a warning of data loss because it cannot know 
            //  that perhaps programmer wants to real only one 
            //  byte from n 
    c = static_cast<char>(n);   // Explicit is always better than implicit 

    f = n;  //  integer will have .0 when it becomes float 
    f = static_cast<float>(n); // better; 

    f = d;  // again implicit type casting with warning 
    // if you want to state that you are interested in 
    //  first four bytes of d then make it explicit 

    f = static_cast<double>(d); 

    enum color 
    {
        WHITE = 0, 
        GRAY, 
        BLACK 
    }col = BLACK;

    float f1 = static_cast<float>(col);  
}

void static_cast_use_cases_2(void)
{
    struct node
    {
        int data; 
        struct node* prev; 
        struct node* next; 
    }; 

    // struct node* p_node = malloc(sizeof(struct node)); // ERROR void* -> T* cannot be implicit
    struct node* p_node = static_cast<struct node*>(malloc(sizeof(struct node))); 
    free(p_node); 
    p_node = NULL; 
}

void static_cast_use_cases_3(void)
{
    class Base
    {
        public: 
            Base() { puts("In Base"); }
    }; 

    class D1: public Base
    {
        private:
        unsigned long long int x1;
        unsigned long long int x2;

        public: 
            D1() : Base ()
            {
                x1 = 0x0;
                x2 = 0x0;
            }
            //D1() : Base() { puts("In D1"); } 
            void f1() { puts("In D1::f1()"); }
            void show()
            {
             printf("x1 = %llx , x2 = %llx\n",x1,x2); 
            }
    }; 

    class D2: public Base
    {
        private:
        int a;
        int b;
        public:

            D2() : Base() { 
                a = 0;
                b = 0 ;
                puts("In D2"); }
            void f2() { 
                a = 0xffff;     
                b = 0xf0f0 ;
            }
    }; 

    class E
    {
        public: 
            E() { puts("In E"); }
            void test() { puts("In E::test()"); }
    }; 

    Base* pBase = new D1; 
    static_cast<D1*>(pBase)->f1(); 
    static_cast<D1*>(pBase)->show();
    puts("After"); // allowed 
    static_cast<D2*>(pBase)->f2();
    static_cast<D1*>(pBase)->show();
      // wrong but no check at runtime 
    // static_cast<E*>(pBase)->test();  // arbitrary casting NOT allowed 
    delete pBase; 
    pBase = 0; 
}