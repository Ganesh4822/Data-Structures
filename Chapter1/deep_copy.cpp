#include<iostream>

class Vect
{
    private:
        int* data;
        int size;

    public:
        Vect(int n)
        {
            size = n;
            data = new int[n];
        }

        Vect(const Vect& obj)
        {
            this->size = obj.size;
            this->data = new int[obj.size];
        }

        Vect& operator=(const Vect& obj)
        {
            this->size = obj.size;
            this->data = new int[obj.size];
            return *this;
        }

        ~Vect()
        {
            delete [] data;
        }


};


int main()
{

}