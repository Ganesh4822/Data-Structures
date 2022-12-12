#include "MapImplementation.h"

char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;

    if (length) {
        randomString = (char*)malloc(sizeof(char) * (length +1));

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
    myDsa::MyMap* map = new myDsa::MyMap();
    map->put("Ganesh",1);
    map->put("S",121212);
    std::cout<<map->getSize()<<std::endl;
    std::cout<<(*map)["Ganesh"]<<std::endl;
    map->PrintMap();
    map->Remove("Ganesh");
    for(int i = 0 ; i < 1000 ; i++)
    {
        char* rand = randstring(10);
        map->put(rand, i);
    }

    map->PrintMap();

    std::cout<<map->getSize()<<std::endl;
    map->Remove("S");
    std::cout<<map->getSize()<<std::endl;
    delete(map);

    std::cout<<"SUCCESS"<<std::endl;
}