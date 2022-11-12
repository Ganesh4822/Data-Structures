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
};