#ifndef _BST_
#define _BST_

#include<stdio.h>
#define SUCCESS 1
#define TRUE 1
#define FALSE 0

typedef int data_t;
// typedef int size_t;
typedef int BOOL;
typedef int status_t;
typedef struct bst_node bst_node_t;
typedef struct bst bst_t;
struct bst_node
{
    int data;
    struct bst_node* parent;
    struct bst_node* right;
    struct bst_node* left;
};

struct bst
{
    struct bst_node* root_node;
    size_t nr_elements;

};

bst_t* create_bst(void);
status_t destroy_bst(bst_t** p_destroy);
bst_node* get_node(data_t data);

status_t add(bst_t* p_bst, data_t data)
{   
    bst_node* p_run = p_bst->root_node;
    while(p_run != NULL)
    {
        if(data  >= p_run->data)
        {
            p_run= p_run->right;
        }
        else if(data < p_run->data)
        {
            p_run = p_run->left;
        }
    }
    bst_node* new_node = get_node(data);
    new_node->parent = p_run;
    
}

status_t remove(bst_t* p_bst, data_t r_data);



bst_node_t* search_node(bst_t* p_bst, data_t* s_data );





void* xcalloc(size_t n_elements, size_t size_per_element);


/*
create
destroy;
remove;
add;
search
*/


#endif