/*
The birthday paradox says that the probability that two people in a room
will have the same birthday is more than half as long as the number of
people in the room (n), is more than 23. This property is not really a paradox,
 but many people find it surprising. Design a C++ program that can
test this paradox by a series of experiments on randomly generated birthdays,
 which test this paradox for n = 5,10,15,20,...,100. You should run
at least 10 experiments for each value of n and it should output, for each
n, the number of experiments for that n, such that two people in that test
have the same birthday
*/
#include <iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>

void generate_n_random_num(int* arr, int n);
int do_experiment(int *arr ,int number_of_people, int frequency);
int compare(const void*,const void*);
void shell_sort(int *arr , int n);
int main()
{
    int n ;
    std::cout<<"Enter number of people"<<std::endl;
    std::cin>>n;
    int *arr;
    arr = (int *)malloc(sizeof(int)*n);
    int count = do_experiment(arr, n,10);
    std::cout<<"For "<<n<<" number of people "<<count<<" times two people in the group were having same birthdates"<<std::endl;
    free(arr);
    arr = 0;
}

int do_experiment(int* arr,int n, int frequency)
{
    int count = 0;
    for(int i = 0 ;i < frequency; i++)
    {
        generate_n_random_num(arr,n);
        qsort(arr,n,sizeof(int),compare);
        for(int j =0 ; j < n ; j++)
        {
            if(arr[j] == arr[j + 1])
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int compare(const void* a, const void* b)
{
    if (*((int*)a) > *((int*)b))
    {
        return 1;
    }
    else
        return -1;
}
void generate_n_random_num(int* arr ,int size)
{
    srand(time(0));
    for(int i =0 ; i< size ; i++)
    {
        arr[i] = (rand()%31);
    }

}


void shell_sort(int* arr, int n)
{
    int gap,i,j,temp;
    for(gap = n/2 ; gap > 0 ;gap  = gap/2)
    {
        for(i = gap ; i < n ; i++)
        {
            for( j = i ; j >=  0 && arr[j] > arr[j+gap]  ; j = j - gap)
            {
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }    
        }
    }
}



