#include<stdio.h>
#include<stdlib.h>

#define INVALID_STACK_NUMBER -3
#define STACK_EMPTY -1
#define STACK_FULL -2
#define SUCCESS 1

typedef int status_t;

class Kstacks
{
    private:
        int *Array;
        int k;
        int partition;
        int *current;

    public:

        Kstacks(int _size, int _k)
        {
            Array = new int[_size];
            k = _k;
            partition = _size / _k;
            current = new int[_k];
        }

        status_t push(int stack_num, int data)
        {
            if(stack_num > k)
                return INVALID_STACK_NUMBER;
            if(current[stack_num - 1] == partition)
                return STACK_FULL;
            current[stack_num - 1]++;
            Array[(partition * (stack_num -1)) +  (current[stack_num - 1] - 1)] =  data;
            return SUCCESS;            
        }

        int top(int stack_num)
        {
            if(stack_num > k )
                return INVALID_STACK_NUMBER;
            printf("Hola\n");
            return Array[(partition * (stack_num - 1)) + (current[stack_num - 1] - 1)];
        }
    
};

int main(int argc , char** argv)
{
    if(argc != 3)
    {
        printf("Please provide current number of Arguments\n");
        return(EXIT_FAILURE);
    }

    int size  = atoi(argv[1]);
    int number = atoi(argv[2]);

    Kstacks* newStack  = new Kstacks(size,number);
    //100 / 10
    //per stack 10 cha size  == partition.
    //2 nd array current[1]++;
    //array[partition * (n - 1) + current - 1];
    //10 *  1 + 0

    for(auto i = 0 ; i < 5 ; i++)
    {
        int status = newStack->push(i+1,i);
    }
    printf("India\n");
    for(auto i = 0 ; i < 5 ; i++)
    {
        printf("top :: %d, stack_num :: %d\n", newStack->top(i),i);
    }

    delete newStack;


}
