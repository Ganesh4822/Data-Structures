#include<stdio.h>
#include<stdlib.h>

#define STACK_EMPTY -1
#define STACK_FULL -2
#define SUCCESS 1
typedef int status_t;

class Astack
{
    private:
        int* Array;
        int size;
        int current;
    
    public:
        Astack(int _size)
        {
            Array = new int[_size];
            size = _size;
            current = 0;
        }

        Astack& operator=(Astack& other) = delete;
        
        Astack(Astack& other) = delete;

        int pop()
        {
            if(0 == current)
            {
                return STACK_EMPTY;
            } 
            current = current -1 ;
            return Array[current -1];
        }

        status_t push(int data)
        {
            if(current  == size)
                return STACK_FULL;
            current ++;
            Array[current - 1] = data;
            return SUCCESS;

        }

        int top()
        {
            return Array[current - 1];
        }

        ~Astack()
        {
            delete[] Array;
        }
};


int main(int argc , char** argv)
{
    if(argc != 2)
    {
        printf("Please provide current number of Arguments\n");
        return(EXIT_FAILURE);
    }

    int size  = atoi(argv[1]);
    Astack* newStack = new Astack(size);

    for(auto i = 0 ; i < 5 ; i++)
    {
        int status = newStack->push(i);
    }

    for(auto i = 0 ; i < 5 ; i++)
    {
        printf("top :: %d\n", newStack->top());
        newStack->pop();
    }

    delete newStack;


}
