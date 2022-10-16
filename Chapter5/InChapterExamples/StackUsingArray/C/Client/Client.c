#include<stdio.h>
#include "IStack.h"

int main()
{
    IStack* obj = ReturnObject(10);
    //obj->Vtable->Function()S
    printf("Size = %d\n",obj->size(obj));
    obj->push(obj,100);
    obj->push(obj,200);
    obj->push(obj,300);
    printf("Size = %d\n",obj->size(obj));
    printf("Top = %d\n",obj->top(obj));
    obj->Destroy(obj);
    printf("SUCCESS\n");
    

}