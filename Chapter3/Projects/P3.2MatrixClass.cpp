/*
P-3.2 Write a C++ program for a matrix class that can add and multiply arbitrary
two-dimensional arrays of integers. Do this by overloading the addition
(“+”) and multiplication (“*”) operators.
*/

#include<iostream>

class Matrix
{
    private:
        int x;
        int y;
        long** M;
    public:
        Matrix(int _x, int _y):x(_x),y(_y)
        {
            M = new long*[x];

            for(int i = 0; i < x ; i++)
            {
                M[i] = new long[y];
            }
            //iniitialize to 0 as well

            for(int i = 0 ; i < x ; i++)
            {
                for(int j = 0 ; j< y; j++)
                {
                    M[i][j] = 0;
                }
            }
        }

        ~Matrix()
        {
            for(int i = 0 ; i < x ;i++)
            {
                free(M[i]);
            }

            free(M);
        }

        void FillMatrix()
        {
            for(int i = 0; i< (this->x); i++)
            {
                for(int j =0 ; j< (this->y) ; j++)
                {
                     M[i][j] = (rand() % 10);
                }
            }
        }

        Matrix* operator*(Matrix& other)
        {
            
            if((this->y != other.x))
            {
                std::cout<<"Sorry Multiplication cannot be computed"<<std::endl;    
                return NULL;
            }
            std::cout<<"control flow here"<<std::endl;

            Matrix* returnMatrix = new Matrix(this->x,other.y);

            for(int i = 0 ; i < this->x ; i++)
            {
                for(int j = 0 ; j < other.y;j++)
                {
                    for(int k = 0; k < this->y ; k++)
                    {
                        returnMatrix->M[i][j] += this->M[i][k] * other.M[k][j];
                    }
                }
            }

            return returnMatrix;
        }

        Matrix* operator+(Matrix& other)
        {
            if((this->x != other.x) && (this->y != other.y))
                return NULL;
            
            Matrix* returnMatrix = new Matrix(this->x, this->y);

            for(int i = 0 ; i < this->x ; i++)
            {
                for(int j = 0 ; j < this->y ; j++)
                {
                    returnMatrix->M[i][j] = this->M[i][j] + other.M[i][j];
                }
            }

            return returnMatrix;
        }

       friend std::ostream& operator<<(std::ostream& os, Matrix& obj);

};

std::ostream& operator<<(std::ostream& os,Matrix& obj)
{
    for(int i = 0 ; i < obj.x ; i++ )
    {
        for(int j = 0 ; j < obj.y; j++)
        {
            os << obj.M[i][j]<<"  ";
        }

        os<<std::endl;
    }

    return os;
}


int main()
{
    Matrix M(4,5);
    M.FillMatrix();
    std::cout<<M;
    std::cout<<"----------------------------------------"<<std::endl;
    Matrix N(4,5);
    N.FillMatrix();
    Matrix G(5,4);
    G.FillMatrix();
    std::cout<<N;
    std::cout<<"----------------------------------------"<<std::endl;
    Matrix* Sum = M + N ;
    std::cout<<*Sum;
    std::cout<<"----------------------------------------"<<std::endl;
    Matrix* mul = M * G;
    std::cout<<*mul;
    std::cout<<"----------------------------------------"<<std::endl;

    delete(Sum);
    delete(mul);
    std::cout<<"SUCCESS"<<std::endl;
    
}