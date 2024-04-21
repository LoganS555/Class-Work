#include <iostream>
#include <fstream>
using namespace std;

// for linked
struct treenode
{
    int dat;
    treenode *lchild;
    treenode *rchild;
};


class bstree
{
 public:
        bstree();
        void in( );
        void pre( );
        void post( );
        void insert( int x );
        void remove( int x );
        bool search( int x );
        int numnodes(); // must compute, not a variable
        int height();   // must compute, not a variable
 private:
        treenode *root;
        void pre( treenode * );
        void in( treenode * );
        void post ( treenode * );
        void insert( treenode *, treenode * );
        bool search( treenode *, int x );
};

bstree::bstree()
{
        root = NULL;
}

void bstree::in()
{
        cout << "in: ";
        in(root);
        cout << endl;
}

void bstree:: in( treenode *r )
{
        if ( r == NULL )
                return;
        in( r->lchild );
        cout << r->dat << " ";
        in( r->rchild );
}

void bstree::pre()
{
        cout << "pre: ";
        pre(root);
        cout << endl;
}

void bstree::pre( treenode *r )
{
        if ( r == NULL )
                return;
        cout << r->dat << " ";
        pre( r->lchild );
        pre( r->rchild );
}

void bstree::post()
{
        cout << "post: ";
        post(root);
        cout << endl;
}

void bstree::post ( treenode *r )
{
        if ( r == NULL )
                return;
        post( r->lchild );
        post( r->rchild );
        cout << r->dat << " ";
}

void bstree::insert( int val )
{
        treenode *t;
        t = new treenode;
        t->dat = val;
        t->lchild = NULL;
        t->rchild = NULL;

        if ( root == NULL )
                root = t;
        else
                insert( root, t);
}

//insert node n into tree rooted at r
void bstree::insert( treenode *r, treenode *n)
{
        if ( r->dat == n->dat )
                return;
        if ( n->dat < r->dat )
        {
                if ( r->lchild == NULL )
                        r->lchild = n;
                else
                        insert( r->lchild, n );
        }
        else
        {
                if ( r->rchild == NULL )
                        r->rchild = n;
                else
                        insert( r->rchild, n );
        }

}

bool bstree::search( int val )
{
        treenode *t;
        t = root;
        if ( t == NULL )
                return false;
        else
                search( t, val );
}

bool bstree::search( treenode *t, int val )
{
        if ( t->dat == val )
                return true;
        if ( t->dat > val)
        {
                if ( t->lchild == NULL )
                        return false;
                else
                        search( t->lchild, val );
        }
        else if ( t->dat < val )
        {
                if ( t->rchild == NULL )
                        return false;
                else
                        search( t->rchild, val );
        }
}



int main(int argc, char *argv[])
{
        bstree t;
        bool r;
        t.insert( 8 );
        t.insert( 5 );
        t.insert( 10 );
        t.insert( 9 );
        t.pre();
        int v;
        cout << "Value to serach: ";
        cin >> v;
        r = t.search(v);
        cout << "Found " << r << endl;

        return 0;
}
