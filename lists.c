#include <stdlib.h>
#include "lists.h"

node * Node(void * data)
{
    node * n = (node *) malloc(sizeof(node));
    if (n)
    {
        n->pnext = NULL;
        n->prev = NULL;
        n->data = data;
    }
    return n;
}
list List()
{
    list l;
    l.head = NULL;
    l.tail=NULL;
    return l;
}

void add(list * l , node * n)
{
    if (l->head == NULL)
        l->head = l->tail = n;
    else
    {
        l->tail->pnext= n;
        n->prev = l->tail;
        l->tail = n;
    }
}

void add_in_location(list* l , node * n , int loc)
{
    int i;
    node  *temp;
    
    if ( l->head == NULL)           //empty
        l->head = l->tail = n;
    else
    {
        if (loc < 1)                //first position
        {
            n ->pnext= l ->head;
            l->head->prev = n;
            l->head = n;
        }
        else
        {
            for(temp = l->head , i = 0 ; temp->pnext && i < loc ; temp = temp->pnext , i++ );
            if (!temp->pnext)   //last position
            {
                l->tail -> pnext = n;
                n->prev = l->tail;
                l->tail = n;
            }
            else                //in position
            {
                n->prev = temp ->prev;
                n-> prev ->pnext = n;
                n->pnext = temp;
                temp->prev = n;
            }
        }
    }
}
void * search( list * l , int (*equality_comparator)(void* , void *) , void * data)
{
    node *temp;
    for(temp = l->head; temp ; temp = temp->pnext )
    {
        if ( (*equality_comparator)( temp->data , data ) )
            return temp->data;
    }
    return NULL;
}
void disp_all(list *l , void (*disp_one)(void*) )
{
    node *temp;
    for(temp = l->head; temp ; temp = temp->pnext )
    {
        (*disp_one)( temp->data );
    }   
}