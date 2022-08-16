#include<iostream>
#include<string>

const std::string days[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday","saturday"};
const std::string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

int is_year_leap(int year);
std::string get_month(int index);
int get_day(int dd, int mm, int yy);
int get_number_of_days(int index,int year);
void print_calender(int year);

int main(int argc,  int *argv[])
{
    print_calender(1998);

}

void print_calender(int year)
{
    std::cout<<"-----Calender------"<<std::endl;

    int current = get_day(1,1,year);

    for(int i = 0; i< 12 ; i++)
    {
        int days = get_number_of_days((i+1),year);
        
        
        std::cout<<"-----------"<<get_month(i)<<"--------------"<<std::endl;

        std::cout<<"sun   mon   tue   wed   thurs   fri   sat"<<std::endl;
        
         for(int k = 0 ; k <= current ;k++)
         {
             std::cout<<"     ";
         }
         int max = current;
         for(int j = 1 ; (j <=  days);)
         {
            for(max = current ; max < 7 ;max++)
            {
                if(j <= days )
                    std::cout<<j<<"     ";
                j++;
                
            }   
            std::cout<<std::endl;

            current = 0;

        }

        current = get_day(1,(i+2),year);
    }

    
}


std::string get_month(int index)
{
    return(months[index]);
}


int is_year_leap(int year)
{
    return !((year % 4) != 0 || ((year % 100) == 0 && (year % 400) != 0));  
}

int get_day(int dd, int mm, int yy)
{
    const int t[12] = {0,3,2,5,0,3,5,1,4,6,2,4};
    yy -= mm < 3;
    return((yy + yy/4 - yy/100 + yy/400 + dd + t[mm -1] ) % 7);
    
}

int get_number_of_days(int month,int year)
{
    if(month == 2)
    {
        if(!is_year_leap(year))
            return 28;
        else 
            return 29;
    }
    else if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12) )
        return 31;
    else 
        return 30;
}




