#include<iostream>
#include<cassert>

class my_vector
{
    private:
        int *p_arr;
        int size;

    public:
        class Iterator;

        my_vector():p_arr(nullptr),size(0){}

        my_vector(const my_vector& other)
        {
            size = other.size;
            p_arr = new int[size];
            memcpy((void*)p_arr, (void*)other.p_arr, size*sizeof(int));

        }

        my_vector(int _size): p_arr(new int[_size]),size(_size)
        {
            memcpy((void*)p_arr, 0, _size*sizeof(int));
        }

        my_vector(int _size, int element):p_arr(new int[_size]),size(_size)
        {
            for(int i = 0 ; i < _size ; i++)
            {
                p_arr[i] = element;
            }
        }

        my_vector(Iterator Iter_1, Iterator Iter_2)
        {
            int len = Iter_1.p - Iter_2.p;
            std::cout << "len=" << len << std::endl; 
            p_arr = new int[len];
            size = len;
            int *p = Iter_1.p;
            for(int i = 0 ; i < len ; i++)
            {
                p_arr[i] = *p++;
            }
            std::cout<<"SUCCESS"<<std::endl;
        }

        ~my_vector()
        {
            delete p_arr;
        }

        class Iterator
        {
            friend class my_vector;
            private:
                int* p;
            
            public:
                Iterator():p(nullptr)
                {

                }
                Iterator(int * _p):p(_p){}

                Iterator operator+(int k)
                {
                    return Iterator(p+k);
                }

                Iterator operator-(int k)
                {
                    return Iterator(p-k); 
                }

                Iterator operator++()
                {
                   p = p +1;
                   return *this;
                }

                Iterator operator--()
                {
                   p = p - 1;
                   return *this;
                }

                int operator*()
                {
                    return *p;
                }

                bool operator==(const Iterator& other){
                    return p == other.p; 
                }

                bool operator!=(const Iterator& other){
                    return p != other.p; 
                }




        };

         void push_back(int new_element)
        {
            size += 1; 
            p_arr = (int*)realloc(p_arr, (size)*sizeof(int)); 
            p_arr[size-1] = new_element; 
        }

        int pop_back()
        {
            int ret = p_arr[size -1];
            size -= 1;
            p_arr = (int*)realloc(p_arr, (size)*sizeof(int));
            return ret;
        }

        Iterator insert(Iterator Iter, int n , int val)
        {
            int old_size = size;
            size = size + n;

        

        }

        Iterator begin()
        {
            return Iterator(p_arr);
        }

        Iterator end()
        {
            return Iterator(p_arr + size);
        }

        int operator[](int i)
        {
            assert(i>= 0 && i < size);
            return *(p_arr + i); 
        }
        int get_size()
        {
            return size;
        }


};

int main()
{
    my_vector v(10,60);

    for(int i = 0; i < v.get_size(); ++i)
        std::cout << "v[" << i << "]:" << v[i] << std::endl; 

    std::cout << "By Iterator" << std::endl; 
    for(my_vector::Iterator iter = v.begin(); 
        iter != v.end(); 
        ++iter)
        std::cout << "*iter=" << *iter << std::endl;

    my_vector::Iterator iter_b = v.begin() + 1; 
    my_vector::Iterator iter_e = v.begin() + 6; 
    my_vector v1(iter_e, iter_b);

    for(my_vector::Iterator iter = v1.begin(); 
        iter != v1.end(); 
        ++iter)
        std::cout << "*iter=" << *iter << std::endl;


 
}