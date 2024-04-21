#include <stdio.h>
#include <stdlib.h>

struct lnode
{
        int data;
        struct lnode *prev;
        struct lnode *next;
};

struct dllheader
{
        struct lnode *begin;
        struct lnode *end;
        int len;
};

struct dllheader *makelist( );
struct lnode *makenode( int val );
void insertFront( struct dllheader *L, int val );
void insertBack( struct dllheader *L, int val );
int isInList( struct dllheader *L, int val );
struct lnode *findNode( struct dllheader *L, int val );
void insertAfter( struct dllheader *L, int val, struct lnode *p );
void insertBefore( struct dllheader *L, int val, struct lnode *p );
void printerF( struct dllheader *alist );
void printerR( struct dllheader *alist );
