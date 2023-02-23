typedef struct InterfaceForDCLL
{
    void* ptr;
    void (*insert_start)(struct InterfaceForDCLL*,int new_data);
    void (*insert_end)(struct InterfaceForDCLL*,int new_data);
    void (*pop_start)(struct InterfaceForDCLL*);
    void (*pop_end)(struct InterfaceForDCLL*);
    void (*insert_after)(struct InterfaceForDCLL*,int);
    void (*insert_before)(struct InterfaceForDCLL*,int);
    void (*delete_element)(struct InterfaceForDCLL*,int);
    void (*destroy_list)(struct InterfaceForDCLL*);

}ILIST;


// struct Node
// {
//     int data;
//     struct node* next;
//     struct node* prev;
// };





