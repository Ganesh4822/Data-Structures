#include<iostream>
#include<ctime>
#include<climits>

int** return_matrix_pointer(int m, int n);

int main()
{
    srand(time(0));
    int **M = return_matrix_pointer(5,6);
    for(int i = 0; i < 5 ; i++)
    {
        for(int j = 0; j< 6 ;j++)
        {
            M[i][j] = rand()% INT16_MAX;
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

    //As Two times the memory is allocated dynamically
    //we first have to delete all rows and then the M pointer

    for(int i = 0 ; i< 5;i++)
    {
        delete[](M[i]);
    }

    delete[](M);

    std::cout<<"SUCCESS"<<std::endl;

}

int** return_matrix_pointer(int m, int n)
{
    int**M = new int*[m];
    for(int i = 0 ; i < m ;i++)
    {
        M[i] = new int[n];
    }

    return M;
}


