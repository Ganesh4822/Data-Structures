#include<iostream>
#include "IStack.h"

int main()
{
    IStack*  obj = IStack::ReturnObject(10);

    obj->push(10);
    obj->push(20);
    std::cout<<"TOP :: "<<obj->top()<<std::endl;
    obj->push(121);
    obj->push(100);
    obj->pop();
    std::cout<<"TOP :: "<<obj->top()<<std::endl;
    std::cout<<"TOP :: "<<obj->size()<<std::endl;

}

//How To Compile

//cl.exe /c /EHsc CstackClient.cpp
//create object File
// Then link the objjcet File given By Server and object File created by client
//link.exe CStack.exe Client.obj  
