#include "dll.h"


struct dllheader *makelist( )
{
    struct dllheader *h;
    h = malloc( sizeof(struct dllheader) );
    h->begin = NULL;
    h->end = NULL;
    h->len = 0;
    return h;
}


struct lnode *makenode( int data )
{
    struct lnode *n;
    n = malloc( sizeof(struct lnode));
    n->data = data;
    n->next = NULL;
        n->prev = NULL;
    return n;

}


void insertFront( struct dllheader *L, int data )
{
        struct lnode *tmp;
        tmp = makenode(data);
        if (L->begin == NULL)
        {
                L->begin = tmp;
                L->end = tmp;
        }
        else
        {
                L->begin->prev = tmp;
                tmp->next = L->begin;
                L->begin = tmp;
        }
        L->len++;
}


void insertBack( struct dllheader *L, int data )
{
        struct lnode *tmp;
        tmp = makenode(data);
        if ( L->end == NULL)
        {
                L->end = tmp;
                L->begin = tmp;
        }
        else
        {
                L->end->next = tmp;
                tmp->prev = L->end;
                L->end = tmp;
        }
        L->len++;
}


int isInList( struct dllheader *L, int data )
{
    struct lnode *m;
    m = L->begin;
    while ( m != NULL )
    {
        if ( m->data == data )
            return 1;
        m = m->next;
    }
    return 0;
}


struct lnode *findNode( struct dllheader *L, int data )
{
    struct lnode *m;
    m = L->begin;
    while ( m != NULL )
    {
        if ( m->data == data )
            return m;
        m = m->next;
    }
    return NULL;
}


void printerF( struct dllheader *alist )
{
        printf("- Forward --(%2d)-------------------\n", alist->len);

    struct lnode *m;
    m = alist->begin;

    while ( m != NULL )
    {
        printf("%2d ", m->data);
        m = m->next;
    }
    printf("\n");

        printf("-----------------------------------\n");
}

void printerR(struct dllheader *alist)
{
        printf("- Reverse --(%2d)-------------------\n", alist->len);

    struct lnode *m;
    m = alist->end;

    while ( m != NULL )
    {
        printf("%2d ", m->data);
        m = m->prev;
    }
    printf("\n");

        printf("-----------------------------------\n");
}

void insertAfter(struct dllheader *L, int val, struct lnode *p)
{
        if ( p == L->end)
        {
                insertBack(L,val);
        }
        else
        {
                struct lnode *tmp;
                tmp = makenode(val);
                tmp->prev = p;
                tmp->next = p->next;
                p->next = tmp;
                p->next->prev = tmp;
                L->len++;
        }
}

void insertBefore(struct dllheader *L, int val, struct lnode *p)
{
        if ( p == L->begin)
        {
                insertFront(L,val);
        }
        else
        {
                struct lnode *tmp;
                tmp = makenode(val);
                tmp->next = p;
                tmp->prev = p->prev;
                p->prev = tmp;
                p->prev->next = tmp;
                L->len++;
        }
}
