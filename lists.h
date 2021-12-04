#ifndef mylist
#define mylist

typedef struct node
{
    struct node * pnext;
    struct node * prev;
    void * data;
} node ;

typedef struct
{
    node * head;
    node * tail;
}list;

node * Node(void * data);
list List();
void add(list * l , node * n);
void add_in_location(list* l , node * n , int loc);
void * search( list * l , int (*equality_comparator)(void* , void *) , void * data);
void disp_all(list *l , void (*disp_one)(void*) );

#endif