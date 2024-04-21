#include <iostream>
#include <iomanip>
using namespace std;

class heap
{
 public:
   heap();
   heap( int n );
   void add( int x );
   int remove();
   void printA();
   bool isEmpty();
   bool isFull();
 private:
   int *arr;
   int SZ;
   int len;
   void upheap();
   void downheap();
};
