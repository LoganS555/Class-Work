#include "maxheap22.h"

// default constructor
heap::heap()
{
        SZ = 32;
        arr = new int[SZ];
        len = 0;
}

//n is the size of the heap array
heap::heap( int n )
{
        SZ = n;
        arr = new int[SZ];
        len = 0;
}

bool heap::isEmpty()
{
        if( len == 0 )
                return true;
        else
                return false;
}

bool heap::isFull()
{
        if(len == SZ-1)
                return true;
        else
                return false;
}

// print the array
void heap::printA()
{
        int i;
        for (i = 1; i <= len; ++i)
                cout << setw(4) << arr[i] ;
        cout << endl;
}



void heap::add( int x )
{
        // do nothing if full
        if(isFull())
        {
                cout << "Full heap, not adding " << x << endl;
                return;
        }

        len++;
        arr[len] = x;
        upheap();

}

int heap::remove()
{
        // do nothing if empty
        if(isEmpty())
        {
                cout << "Heap empty, no value removed" << endl;
                return 0;
        }
        int big;
        big = arr[1];

        arr[1] = arr[len];
        arr[len] = 0;
        len--;
        downheap();

        return big;
}



// start at item last, move it up until
//   heap property is restored
void heap::upheap()
{
        int cur, par;
        int tmp;
        cur = len;
        par = cur/2;

        while ( par > 0 && arr[cur] > arr[par] )
        {
                tmp = arr[cur];
                arr[cur] = arr[par];
                arr[par] = tmp;

                cur = par;
                par = cur/2;
        }

}


// start at item 1, move it down until
//   heap property is restored
// ** swap with larger child & repeat
void heap::downheap()
{
        int par, lchild, rchild;
        int tmp;

        par = 1;
        lchild = par * 2;
        rchild = par * 2 + 1;

        while ( (lchild <= len && arr[par] < arr[lchild] ) || (rchild <= len && arr[par] < arr[rchild] ) )
        {
                if(arr[lchild] > arr[rchild])
                {
                        tmp = arr[lchild];
                        arr[lchild] = arr[par];
                        arr[par] = tmp;
                        par = lchild;
                }
                else
                {
                        tmp = arr[rchild];
                        arr[rchild] = arr[par];
                        arr[par] = tmp;
                        par = rchild;
                }
                lchild = par * 2;
                rchild = par * 2 + 1;
        }

}
