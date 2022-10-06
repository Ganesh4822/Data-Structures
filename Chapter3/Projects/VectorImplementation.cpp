#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>

class my_vector
{
    private:
    int* p_arr;
    std::size_t size;

    public:
    class Iterator;
    typedef std::size_t size_type;

    my_vector():p_arr(nullptr),size(0){}

    //copy constructor
    my_vector(const my_vector& other)
    {
        size = other.size;
        p_arr = new int[size];
        memcpy((void*)p_arr, (void*)other.p_arr,size* sizeof(int));
    }

    my_vector(size_type _size): p_arr(new int[_size]), size(_size)
    {
        memset((void*)p_arr,0,_size*sizeof(int));
    }

    my_vector(size_type _size, int element):p_arr(new int[_size])
    {
        for(int i = 0 ; i < _size; i++)
        {
            p_arr[i] = element;
        }
    }

    my_vector(Iterator iter_1, Iterator iter_2)
    {
        std::size_t len = iter_1.p - iter_2.p;
        p_arr = new int[len];
        size = len;
        int *p = iter_1.p;
        for(size_type i = 0; i < len ; ++i)
        {
            p_arr[i] = *p++;
        }
    }

    ~my_vector()
    {
        delete[] p_arr;
    }

    class Iterator
    {
        friend class my_vector;
        int* p;

        public:
        Iterator():p(nullptr){}
        Iterator(int* _p) : p(_p){}

        Iterator operator+(size_type k)
        {
            return Iterator(p+k);
        }

        Iterator operator-(size_type k)
        {
            return Iterator(p-k);
        }

        Iterator operator++()
        {
            p+= 1;
            return *this;
        }

        Iterator operator--()
        {
            p-= 1;
            return*this;

        }

        int operator*()
        {
            return *p;
        }

        bool operator==(const Iterator& other)
        {
            return p == other.p;
        }

        bool operator!=(const Iterator& other)
        {
            return p!=other.p;
        }


    };

    Iterator begin()
    {
        return Iterator(p_arr);
    }

    Iterator end()
    {
        return(p_arr + size);
    }

    int operator[](size_type i)
    {
        return *(p_arr + i);
    }

    void push_front(int element)
    {
        size = size + 1;
        p_arr = (int*)realloc(p_arr,size*sizeof(int));
        for(int i = size - 2; i > -1 ;i--)
        {
            p_arr[i+1] = p_arr[i];
        }

        p_arr[0] = element;

    }

    int pop_back()
    {
        int ret = p_arr[size-1];
        size = size - 1;
        p_arr = (int*)realloc(p_arr,size*sizeof(int));
        return ret;
    }

    Iterator insert(Iterator iter,int n , int element)
    {
        std::size_t iter_index = iter.p - p_arr;
        std::size_t old_size = size;
        size = size + n;
        p_arr = (int*)realloc(p_arr,size*sizeof(int));
        for(std::size_t i = old_size - 1; i > iter_index - 1 ; i-- )
        {
            p_arr[i+n] = p_arr[i];

        }
        for(std::size_t i = 0 ; i< n; i++)
        {
            p_arr[iter_index + 1] = element;
        }

        return Iterator(iter_index + p_arr);
    }
};