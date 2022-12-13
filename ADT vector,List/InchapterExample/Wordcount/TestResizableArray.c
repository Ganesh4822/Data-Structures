#include "ResizableArray.h"
char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}
int main()
{
    vector* vec = createVector();

    int i;
    for( i = 0 ; i  < 100000 ; i++)
    {
        char* rands = randstring(10);
        pushBack(vec, rands);

    }

    showVector(vec);
    DeleteVector(vec);
    
}