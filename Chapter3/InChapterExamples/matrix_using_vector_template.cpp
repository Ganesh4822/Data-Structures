#include<iostream>
#include<vector>
#include<climits>

int main()
{
    int n = 5;
    int m =6;
    std::vector< std::vector<int> >M(n,std::vector<int>(m));

    for(int i =0 ; i< n ;i++)
    {
        for(int j = 0; j<m ; j++)
        {
            M[i][j] = rand()%INT16_MAX;
        }
    }

    for(int i = 0; i < 5 ; i++)
    {
        for(int j = 0; j< 6 ;j++)
        {
            std::cout<<M[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}


