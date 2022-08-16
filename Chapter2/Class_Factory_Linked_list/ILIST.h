#ifndef _ILIST_H
#define _ILIST_H

#include<objbase.h>
#define STDCALL _stdcall

const IID IID_LIST = 
{//0edfc552-e0a0-4966-b636-a77fa75101e8
    0x0edfc552,
    0xe0a0,
    0x4966,
    {0xb6,0x36,0xa7,0x7f,0xa7,0x51,0x01,0xe8}
};


class ILIST : public IUnknown
{
    public:
        virtual int insert_beg(int new_data) = 0;
        virtual int insert_end(int new_data) = 0;
        virtual int insert_after_data(int a_data, int new_data);
        virtual int insert_before_data(int b_data, int new_data);
        virtual int del_beg(void) = 0; 
	    virtual int del_end(void) = 0; 
	    virtual int del_data(int d_data) = 0;
        virtual bool search(int s_data) = 0; 
	    virtual void display(void)  = 0; 
	    virtual bool is_empty(void)= 0;
        virtual ~ILIST();
};

#endif