/*
P-3.7 Write a program that can perform encryption and decryption using an arbitrary substitution cipher. In this case, the encryption array is a random
shuffling of the letters in the alphabet. Your program should generate
a random encryption array, its corresponding decryption array, and use
these to encode and decode a message.
*/

#include<iostream>
#include<cTime>
#include<string>
#include<vector>

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;

}

class Cipher
{
    private:
        char EncryptionArray[26];

    public:
        Cipher()
        {   
            
            for(int i = 0 ; i < 26 ; i++)
            {
                EncryptionArray[i]  = 'A'+ i;
            }

            for(int i = 0 ; i< 26 ; i++)
            {
                std::cout<<EncryptionArray[i]<<" ";
            }
            std::cout<<std::endl;

            for(int i = 0 ; i < 26 ; i++)
            {
                int j = rand() % 26;
                swap(&EncryptionArray[i], &EncryptionArray[j]);
            }

            for(int i = 0 ; i< 26 ; i++)
            {
                std::cout<<EncryptionArray[i]<<" ";
            }
            std::cout<<std::endl;

        }

        std::string EncryptMessage(std::string message)
        {   int  i = 0 ;
            
            while(message[i] != '\0')
            {
                if(message[i] == 32)
                    ++i;
                //std::cout<<i<< EncryptionArray[message[i] - 65]<<" ";
                message[i] = EncryptionArray[message[i] - 65];
                i++;
                
            }
            return message;
        }

        std::string DecryptMessage(std::string message)
        {   
            int i = 0;
            
            while(i < message.length())
            {
                if(message[i] == 32)
                {
                    ++i;
                    continue;
                }
                    
                for(int j = 0 ; j<26 ; j++)
                {
                    if(message[i] == EncryptionArray[j])
                    {
                       // std::cout<<i<<" "<< j <<" "<<EncryptionArray[j]<<" "<<message[i]<<" "<<'A' + j<<std::endl;
                        message[i] = 'A' + j; 
                        break;
                    }
                }  

                i++;      
            }
            //std::cout<<message<<std::endl;

            return message;
        }

        // void show()
        // {
        //     for(int i = 0 ; i< 26 ; i++)
        //     {
        //         std::cout<<EncryptionArray[i]<<" ";
        //     }
        //     std::cout<<std::endl;
        // }


};

int main()
{
    srand(time(NULL));
    Cipher c;
    std::string message = "MY NAME IS GANESH INGALE"; 
    message = c.EncryptMessage(message);
    
    std::cout<<message<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
    message = c.DecryptMessage(message);
    std::cout<<message<<std::endl;
    //Hacking
    //By using Casting We can Easily access the Private Encryption Array 
    //Hence This Encryption cipher class is not safe 
    //This problem can be solved by Using Interface and Hiding the details from the client
    std::cout<<"ELements is"<<((char*)&c)<<std::endl;
    
}