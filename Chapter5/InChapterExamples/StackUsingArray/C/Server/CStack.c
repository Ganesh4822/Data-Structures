#include<stdio.h>
#include<stdlib.h>
#include "IStack.h"



// typedef struct CStack_VTABLE
// {
//      int (*size)(CStack*);
//      int (*empty)(CStack*);
//      int (*top)(CStack*);
//      void (*push)(CStack*,int);
//      void (*pop)(CStack*);
// }CStack_VTABLE;

typedef struct CStack
{
    IStack* V_Table;
    //struct CStack* this;
    int capacity;
    int* S;
    int t;

}CStack;

int size(IStack* obj);
int empty(IStack* obj);
int top(IStack* obj);
void push(IStack* obj,int i);
void pop(IStack* obj);
void Destrot(IStack* obj);

IStack* ReturnObject(int _capacity)
{
    CStack* obj = (CStack*)malloc(sizeof(CStack));
    //printf("Address of obj %p\n",obj);
    obj->capacity = _capacity;
    obj->S = (int*)malloc(sizeof(int)*(_capacity));
    obj->t = -1;
    obj->V_Table = (IStack*)malloc(sizeof(IStack));
    //printf("Address of vtable %p\n",obj->V_Table);
    obj->V_Table->size = &size;
    obj->V_Table->empty = &empty;
    obj->V_Table->top = &top;
    obj->V_Table->push = &push;
    obj->V_Table->pop = &pop;
    obj->V_Table->Destroy = &Destrot;
    //obj->this = obj;
    obj->V_Table->ptr = obj;
    return (IStack*)obj->V_Table;   
}

int size(IStack* obj)
{   
    //printf("Address of IStack %p\n",obj);
    CStack* this = obj->ptr;
    return(this->t + 1);
}

int empty(IStack* obj)
{
    CStack* this = obj->ptr;
    return(this->t < 0);  
}

int top(IStack* obj)
{   CStack* this = obj->ptr;
    if(!empty(obj))
        return this->S[this->t];
}

void push(IStack* obj,int i)
{           
    CStack* this = obj->ptr;
    if(size(obj) != this->capacity)
        this->S[++(this->t)] = i;
    else    
        printf("Stack is Full\n");
}

void pop(IStack* obj)
{
    CStack* this = obj->ptr;
    if(!empty(obj))
        --(this->t);
    else
        printf("Stack is already Empty");  
}

void Destrot(IStack* obj)
{
    CStack* this = obj->ptr;
    free(this->S);
    free(this->V_Table);
    free(this);
}