#include<cstdlib>
#include<iostream>

class Date{
    private:
        int day,month,year;

    public:
        Date()
        {
            day = 1;
            month = 1;
            year = 1970;
        }
        Date(int _day, int _month, int _year):day(_day),month(_month),year(_year){}
        friend std::ostream& operator<<(std::ostream& os, Date& objDate);
        friend std::istream& operator>>(std::istream& is, Date& objDate);       



};

std::ostream& operator<<( std::ostream& os, Date& objDate)
{
    os<<objDate.day<<"-"<<objDate.month<<"-"<<objDate.year<<std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Date& objDate)
{
    std::cout<<"Enter day";
    is>>objDate.day;
    std::cout<<"Enter month";
    is>>objDate.month;
    std::cout<<"Enter year";
    is>>objDate.year;
    return is;
}

int main()
{
    Date d;
    std::cout<<"Enter date"<<std::endl;
    std::cin>>d;
    std::cout<<"show date object"<<std::endl;
    std::cout<<d;

}