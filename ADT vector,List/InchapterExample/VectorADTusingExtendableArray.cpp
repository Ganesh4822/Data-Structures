
#include<iostream>
#include<algorithm>
class ArrayVector
{
    private:
        int capacity;
        int n;
        int* A;
    public:
        ArrayVector();
        ~ArrayVector();
        int size() const;
        bool empty() const;
        int& operator[](int i);
        int& at(int i);
        void erase(int i);
        void insert(int i , int val);
        void reserve(int n);


};

ArrayVector::ArrayVector():capacity(0),n(0),A(nullptr)
{

}

ArrayVector::~ArrayVector()
{
    delete[] A;
}

int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return(size() == 0);
}

int& ArrayVector::operator[](int i)
{
    return A[i];
}

int& ArrayVector::at(int i)
{
    return A[i];
}

void ArrayVector::erase(int i)
{
    for(int j = i + 1 ; j < n ; j++)
        A[j -1] = A[j];
    n--;
}

void ArrayVector::insert(int i , int val)
{
    if(n >= capacity)
        reserve(2*capacity);
    for(int j = n- 1 ; j >= i; j--)
        A[j+1] = A[j];
    A[i] = val;
    n++;

}

void ArrayVector::reserve(int N)
{
    if(capacity > N) return;
    int* B = new int[N];
    for(int i = 0 ; i< n ;i++)
    {
        B[i] = A[i];
    }
    if(A != nullptr)
        delete[] A;
    A = B;
    capacity = N;
}

