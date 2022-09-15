#include<iostream>
#include<vector>

std::vector<int> Find5repetatedelements(int* arr, int n)
{
    std::vector<int>ans;
    for(int i = 0; i< n ; i++)
    {
        if(arr[arr[i]] > 0)
        {
            arr[arr[i]] = - arr[arr[i]];
        }
        else{
            ans.push_back( abs(arr[arr[i]]));
        }


    }
    return ans;
}