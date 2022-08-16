#include<iostream>

char* remove_punctuations(char* ostring, int n)
{   
    int count = 0;
    // for(int i = 0 ; i < n ;i++)
    // {
    //     if(ostring[i] > 33 && ostring[i] < 47 )
    //     {
    //         count++;
            
    //     }
    // }

    // printf("count is %d",count);

    char* new_string = (char*)malloc(sizeof(ostring));
    for(int i = 0,j = 0; i< n ; i++)
    {
        if(!(ostring[i] > 33 && ostring[i] < 47))
        {   
            new_string[j] = ostring[i];
            j++;
            //printf("%c\n",ostring[i]);    
        }
        
    }
    
    return new_string;
}


int main()
{
    char* orstring ="Let's try, Mike.";
    char* otstring = remove_punctuations(orstring,19);
    printf("%s",otstring);
    delete (otstring);
    

}