#ifndef _LISTSERV_H 
#define _LISTSERV_H 

#include "ILIST.h"

typedef struct node
{
    int data;
    node* next;
    node* prev;
}node_t;

class CLIST : public ILIST
{
    public:
        HRESULT STDCALL QueryInterface(const IID& ref, void** ppv); 
        ULONG STDCALL AddRef(); 
        ULONG STDCALL Release();

         int insert_beg(int new_data) = 0;
         int insert_end(int new_data) = 0;
         int insert_after_data(int a_data, int new_data);
         int insert_before_data(int b_data, int new_data);
         int del_beg(void) = 0; 
	     int del_end(void) = 0; 
	     int del_data(int d_data) = 0;
         bool search(int s_data) = 0; 
	     void display(void)  = 0; 
	     bool is_empty(void)= 0;
         ~CLIST();
         CLIST();

    private:
         node_t* head;
         static int m_Ref;
         static void generic_insert(node_t* beg, node_t* mid, node_t* end);
         static void generic_delete(node_t* node_delete);
         static node_t* search_node(node_t* list, int data);
         static node_t* get_node(int new_data);

};
#endif