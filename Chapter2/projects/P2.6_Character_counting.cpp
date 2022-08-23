#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

// some proble is there not completed
int SIZE = 26;
class FileReader
{
    private:
        std::string FileName;
        int* arr;

    
    public:
        FileReader(std::string file):FileName(file)
        {
            arr = 0;
        }

        void FillArray()
        {
            std::ifstream inf{this->FileName};
            std::string str;
            while(inf)
                {
                    std::string str;
                    std::getline(inf, str);
                    this->arr = count_array(str);
                }
        }

        static int* count_array(std::string str)
        {
            int * arr  = (int*)calloc(26,sizeof(int));
            std::cout<<str;
            for (int i = 0; i < str.size(); i++)
            {   
                arr[str[i] - 'a']++;
            }

            // for(int i = 0; i< 26 ; i++)
            // {
            //     std::cout << " " << arr[i];
            // }
                
            return arr;
        }


        void print()
        {
            for(int i = 0; i< 26 ; i++)
            {
                std::cout << " " << this->arr[i];
            }
        }

        friend std::ostream& operator <<(std::ostream& os,FileReader& fileobj);
    

};

std::ostream& operator <<(std::ostream& os,FileReader& fileobj)
{
    std::ifstream inf{fileobj.FileName};
    while(inf)
    {
        std::string str;
        std::getline(inf, str);
        os<< str<<std::endl;
    }

    return os;
}

int main()
{
    FileReader f("random.txt");
    f.FillArray();
    f.print();
    //std::cout<<f;

    
    
}   