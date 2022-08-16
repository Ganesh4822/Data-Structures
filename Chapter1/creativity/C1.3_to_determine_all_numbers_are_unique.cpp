#include<vector>
#include<iostream>
void shell_sort(int* arr, int n);
int main()
{
    std::vector<int>arr(10);

    for(int i = 0; i < 10 ; i++)
    {
        arr[i] = i;
    }

    //  *vec = arr;
    // shell_sort(arr, 10);

}


void shell_sort(int* arr , int n)
{
    int gap,i,j,temp;
    for(gap = n/2 ; gap > 0 ; gap = gap/2)
    {
        for(i = gap ; i < n; i++ )
        {
            for(j = i -gap ; j>=0 && arr[j] > arr[j+gap] ; j = j -gap)
            {
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }
        }
    }
}
