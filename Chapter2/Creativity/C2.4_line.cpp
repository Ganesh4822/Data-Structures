/*
C-2.4 Design a class Line that implements a line, which is represented by the formula y = ax+b.
Your class should store a and b as double member variables. Write a member function intersect(ℓ) that returns the x coordinate
at which this line intersects line ℓ. If the two lines are parallel, then your
function should throw an exception Parallel. Write a C++ program that
creates a number of Line objects and tests each pair for intersection. Your
program should print an appropriate error message for parallel lines.
*/
#include<iostream>

class ParallelException{
    private:
        std::string err;
    public:
        ParallelException(std::string _err):err(_err){}
        std::string getError()
        {
            return err;
        }
};

class Line
{
    private:
        double a;
        double b;
    public:

    Line(double _a, double _b):a(_a),b(_b){}
    double intersect(const Line& other)
    {
        if(this->a == other.a)
        {
            throw ParallelException("Line are parralel");
        }
        return (other.b - this->b/other.a - this->a); 
    }
};

int main()
{
    Line l1(10,20);
    Line l2(2,2);
    Line l3(4,2);
    Line l4(17,45);

    Line l5(1,1);
    Line l6(1,6);
    
    try
    {
        l5.intersect(l6);
    }catch(ParallelException e)
    {
        std::cout<<e.getError()<<std::endl;
    }

    Line array[] = {l1,l2,l3,l4};

    int n = 4;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            try{
                if(i != j)
                {
                    std::cout<<array[i].intersect(array[j])<<std::endl;
                }
            }catch(ParallelException e){
                std::cout<<e.getError()<<std::endl;
            }
        }
    }


}



