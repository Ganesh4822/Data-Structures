/*
C-2.6 Write a C++ class that is derived from the Progression class to produce
a progression where each value is the square root of the previous value.
(Note that you can no longer represent each value with an integer.) You
should include a default constructor that starts with 65,536 as the first
value and a parametric constructor that starts with a specified (double)
number as the first value.
*/

#include<iostream>
#include<cmath>

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
            std::cout<<firstValue()<<std::endl;
            for(int i = 2; i <= n; i++)
            {
                std::cout<< " " <<nextValue()<<std::endl;    
            }
        }
};


class SquareRootProgression : public Progression
{
    public:
        SquareRootProgression():Progression(65536){}
        SquareRootProgression(long _startValue):Progression(_startValue){}

        virtual long nextValue()
        {
            cur = sqrt(cur);
            return cur;
        }



};

int main(int argc, char** argv)
{
    // if(argc == 2)
    // {
    //     Progression* p = new SquareRootProgression(reinterpret_cast<long>(argv[1]));
    //     p->printProgression(5);

    // }
    //Here random value is read as an input as we have used reinterpretcast here reads 8 bytes.
    //todo
    
    Progression* p = new SquareRootProgression();
    p->printProgression(5);
    delete(p);
    p = NULL;

}