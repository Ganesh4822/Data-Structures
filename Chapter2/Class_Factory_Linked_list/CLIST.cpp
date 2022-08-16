#include"CLIST.h"
#include<iostream>
#include<cstdlib>

//generic routines

void CLIST::generic_insert(node_t *beg, node_t *mid, node_t *end)
{
     mid -> next = end;
     mid -> prev = beg;
     beg ->next = end;
     end -> prev = beg;

}

void CLIST::generic_delete(node_t* node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete(node);
}

node_t* CLIST::search_node(node_t *head, int s_data)
{
	for(node_t *run = head->next; run != head; run = run->next)
			if(run->data == s_data)
				return run; 

	return NULL; 
}


node_t* CLIST::get_node(int new_data)
{
    node_t* new_node = new node_t;
    new_node->data = new_data;
    return new_node;
}



//public methods

HRESULT STDCALL CLIST::QueryInterface(const IID& ref, void** ppv)
{
    if(ref == IID_IUnknown)
    {
        //todo
    }
    else if(ref == IID_LIST)
    {
        *ppv = static_cast<ILIST*>(this);
    }
    else
    {
        *ppv = 0;
        return E_NOINTERFACE;
    }

    if(*ppv)
    {
        reinterpret_cast<IUnknown*>(*ppv) -> AddRef();
    }

    return S_OK;

}

ULONG STDCALL CLIST::AddRef()
{
    ++m_Ref;
    return m_Ref;
}