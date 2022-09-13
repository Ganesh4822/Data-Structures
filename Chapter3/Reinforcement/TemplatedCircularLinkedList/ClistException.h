#include<iostream>
#include<stdexcept>


class CListEmpty : public std::logic_error
{
    public:
        CListEmpty(const char* msg ): std::logic_error(msg){}
};

class CListDataNotFound : public std::domain_error
{
    public:
        CListDataNotFound(const char* msg) : std::domain_error(msg){}
};