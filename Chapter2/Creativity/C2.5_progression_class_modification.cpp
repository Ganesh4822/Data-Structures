#include<iostream>

class Progression
{
    protected:
        long first;
        long cur;

        virtual long firstValue()
        {
            cur = first;
            return cur;
        }
        virtual long nextValue() = 0;
    public:
        Progression(long f = 0)
        {
            first = f;
            cur = f;
        }

        virtual ~Progression(){};
        void Progression::printProgression(int n)
        {
            std::cout<<firstValue();
            for(int i = 2; i <= n; i++)
            {
                std::cout<< " " <<nextValue()<<std::endl;    
            }
        }
};

class Absolute: public Progression
{
    private:
        long second;
    
    public:
        Absolute()
        {
            first = 2;
            second = 200;
        }

        Absolute(long _first, long _second):Progression(_first),second(_second){}

        virtual long nextValue()
        {
            long temp = second - first;
            first = second;
            second = temp;
            cur = second;
            return second;
        }

        ~Absolute()
        {
            
        }
    
};


int main()
{
    Progression* p = new Absolute();
    p->printProgression(10);
    delete(p);
    p = NULL;
}

