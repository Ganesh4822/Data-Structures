#include<iostream>

class my_string 
{
    private:
     char *buf = nullptr;
     unsigned int size = 0;

    public:
        my_string(): buf(nullptr), size(0)
        {

        }

        my_string(const char* buffer)
        {
            size = strlen(buffer);
            buf = new char[size + 1];
            strncpy_s(buf,size+1, buffer,size);

        }

        my_string(const my_string& obj)
        {
            size = obj.size;
            buf = new char[size +1];
            strncpy_s(buf,size+1, obj.buf,size);
        }

        my_string& operator=(const my_string& other_obj)
        {
            size = other_obj.size;
            buf = new char[size + 1];
             strncpy_s(buf,size+1, other_obj.buf,size);
             return *this;
        }

        my_string& operator+(const my_string& other)
        {
            my_string new_string;
            new_string.size = this->size + other.size;
            new_string.buf  = new char[new_string.size + 1];
            strncpy_s(new_string.buf , this->size +1, this->buf , this->size);
            strncpy_s(new_string.buf + this->size , other.size + 1, other.buf, other.size);
            return new_string;

        }
};