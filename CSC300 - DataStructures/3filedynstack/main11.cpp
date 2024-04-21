#include "stack11.h"

int main()
{
 stack s;
 stack t(5);
 int x;
 int i;
 for (i = 1; i < 10; ++i)
   t.push( i );
 t.print();

 s.push( 4 );
 s.push( 6 );
 s.print();
 x = s.top();
 cout << x << " is at top of stack " << endl;
 s.print();
 x = s.pop();
 cout << x << " is at top of stack " << endl;
 s.print();

 while ( ! t.isEmpty() )
  {
    x = t.pop();
    cout << " t popped --- " << x << endl;
  }
 return 0;
}
