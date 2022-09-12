#include<iostream>
#include<ctime>
#include<cstdlib>

int Random(int);
void RemoveRandomEntry(int* , int,int);
int* ResizeArray(int* a, int newLenght);


int main()
{
    int n;
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    int i;
    for(i = 0; i< n ; i++)
        scanf("%d",&arr[i]);
    
    int num = Random(n);
    std::cout<<"Entry"<<num<<std::endl;
    RemoveRandomEntry(arr,n,num);
    std::cout<<"SUCCESS"<<std::endl;
       
}

int Random(int k)
{
   srand(time(0));
   int num = rand() % k;
   return num; 
}

void RemoveRandomEntry(int* a, int len, int EntryToRemove)
{
    
    if(len > 0)
    {
    
        int temp = a[len -1];
        a[len-1] = a[EntryToRemove];
        a[EntryToRemove] = temp;
        a[len-1] = 0;
    
        a  = ResizeArray(a,len);
    
        if((len -1) != 0)
            {
                EntryToRemove = Random(len - 1);
            }
        else{
        EntryToRemove = 0;
            }
        RemoveRandomEntry(a,len -1,EntryToRemove);
    }
    else
    {
        return;
    }

}

int* ResizeArray(int* a, int newLenght)
{
    a = (int*)realloc(a,sizeof(int)*newLenght);
    return a;
}


//Recursion Trace
/*
RemoveRandomEntry(a,4,2)
*/

