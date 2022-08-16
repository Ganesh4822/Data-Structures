
typedef struct List_Generic
{
    int (*insert_start)(void* List_Type, void* data);
    int (*insert_end)(void* List_Type, void* data);
    void* (*pop_start)(void* List_Type);
    void* (*pop_end)(void* List_Type);
    int (*delete_start)(void* List_Type);
    int (*delete_end)(void* List_Type);
    

};