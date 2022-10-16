
typedef struct InterfaceForStack
{
     void* ptr;
     int (*size)(struct InterfaceForStack*);
     int (*empty)(struct InterfaceForStack*);
     int (*top)(struct InterfaceForStack*);
     void (*push)(struct InterfaceForStack*,int e);
     void (*pop)(struct InterfaceForStack*);
     void (*Destroy)(struct InterfaceForStack*);


     //InterfaceForStack* ReturnObject(int);
}IStack;

IStack* ReturnObject(int);

