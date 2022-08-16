#include<iostream>

template<typename T>
class BasicVector
{   private:
        T* arr;
        int capacity;
    public:
        BasicVector(int _capacity = 10);
        T& operator[](int i)
        {
            return arr[i];
        }
        ~BasicVector();
        
};

template<typename T>
BasicVector<T>::BasicVector(int _capacity)
{
    capacity = _capacity;
    arr = new T[capacity];
}


template<typename T>
BasicVector<T>::~BasicVector()
{
    delete arr;
}


int main()
{
    BasicVector<int> a(10);
}