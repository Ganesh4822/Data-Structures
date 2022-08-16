#include<iostream>

class Progression
{
    protected:
        long first;
        long cur;

        virtual long firstValue();
        virtual long nextValue();
    public:
        Progression(long f = 0)
        {
            first = f;
            cur = f;
        }

        virtual ~Progression(){};
        void printProgression(int n);
};

void Progression::printProgression(int n)
{
    std::cout<<firstValue();
    for(int i = 2; i <= n; i++)
    {
        std::cout<< " " <<nextValue()<<std::endl;    
    }

}

long  Progression::firstValue()
{
    cur = first;
    return cur;
}

long Progression::nextValue()
{
    return  (++cur);
}


class ArithProgression : public Progression
{
    protected:
        long inc;

        virtual long nextValue();
    public:
        ArithProgression(long i = 1);

};

ArithProgression::ArithProgression(long i):Progression(1), inc(i){}

long ArithProgression::nextValue()
{
    cur += inc;
    return cur;
}


class GeomProgression:public Progression
{
    protected:
        long base;

        virtual long nextValue();
    public:
        GeomProgression(long base = 2);
};


GeomProgression::GeomProgression(long _base) : Progression(1), base(_base){}

long GeomProgression::nextValue()
{
    cur *= base;
    return (cur);
}


class FibonacciProgression : public Progression
{
    protected:
        long second;
        long prev;

        virtual long firstValue();
        virtual long nextValue();
    
    public:
        FibonacciProgression(long f = 0, long s = 1);


};

FibonacciProgression::FibonacciProgression(long _f, long _s):Progression(_f),second(_s),prev(second -first){}

long FibonacciProgression::firstValue()
{
        cur = first;
        prev = second - first;
        return cur;
}

long FibonacciProgression::nextValue()
{
    long temp = prev;
    prev = cur;
    cur = cur + temp;
    return cur;
}


int main()
{
    Progression* p = new GeomProgression(2);

    reinterpret_cast<Progression*>(p)->printProgression(10);
    //p->printProgression(10);

    delete(p);

}