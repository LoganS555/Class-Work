#include "stack11.h"

stack::stack()
{
        toploc = 0;
        dat = new int[20];
        cap = 20;
}

stack::stack(int sz)
{
        toploc = 0;
        dat = new int[sz];
        cap = sz;
}

void stack::push( int x )
{
        if( toploc == cap)
        {
                cout << "stack is full " << endl;
                return;
        }
        dat[toploc] = x;
        toploc++;
}

int stack::pop( )
{
        if( !isEmpty() )
                return dat[--toploc];
        return -1;
}

int stack::top( )
{
        return dat[toploc - 1];
}

bool stack::isEmpty( )
{
        if (toploc == 0)
                return true;
        else
                return false;
}

void stack::print( )
{
 int i;
 for (i = 0; i < toploc; ++i)
   cout << setw(3) << i ;
 cout << endl;
 for (i = 0; i < toploc; ++i)
   cout << setw(3) << dat[i] ;
 cout << "   <--top ";
 cout << endl;
}
