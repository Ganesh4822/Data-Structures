//TODO


/*
C-2.9 Write a C++ program that can input any polynomial in standard algebraic
notation and outputs the first derivative of that polynomial.
*/

// #include<iostream>
// #include<string>



// class Polynomial
// {
//     private:
//         int degree;
//         int *arr;
    
//     public:
//        Polynomial(int _degree):degree(_degree)
//        {
//         arr = new int(degree);
//        } 

//        void TakeCoeff()
//        {
//         std::cout<<"take coeffcients"<<std::endl;
//         for(int i = 0 ; i< degree ; i++)
//         {
//             std::cin>>arr[i];    
//         }
//        }

//        void PrintPolynomial() const
//        {
//          for(int i = degree - 1,j = 0 ; i >=0, j<degree ; i--,j++)
//          {
//             if(arr[j] == 0)
//             {
//               continue;
//             }
//             else if(j == (degree - 1))
//             {
//                 std::cout<<arr[j]<<std::endl;
//             }
//             else
//             {
//                 std::cout<<arr[j]<<"x^"<<i<< "+ ";
//             }
            
//          }  
//        }

//        ~Polynomial()
//        {
//         delete arr;
//        }
// };

// class Polynomial
// {
//     private:
//         std::string expression;
//     public:
//         Polynomial(std::string _expression)
//         {
//             expression = _expression;
//         }

//         void PrintPolynomial()
//         {
//             std::cout<<expression<<std::endl;
//         }

//         void FindFirstDerivative()
//         {
//             std::string derived_expression = "";
//             int i = 0;
//             std::string coeffString;
//             std::string powerString;
//             while(this->expression[i] != '\0')
//             {
//                 switch (expression[i])
//                 {
//                 case 'x' :
//                     coeffString.push_back(expression[i - 1]);
//                     i++;
//                     break;

//                 case '^':
//                     if(expression[i] >= 49 && expression[i] <= 57)
//                     powerString.push_back()
                
//                 default:
//                     break;
//                 }
//             }
            
//         }

// };

// int main(void)
// {
//     Polynomial obj("2x^2 + 4x + 9");
    

// }