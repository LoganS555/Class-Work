#include <fstream>
using namespace std;

#include "maxheap22.h"

int main(int argc, char *argv[])
{
        ifstream ifp( argv[1] );

        heap h;

        int x;

        ifp >> x;

        while ( x != 0 )
        {
                if ( x == 1 )
                {
                        ifp >> x;
                        h.add( x );
                }
                else if ( x == -1 )
                        h.remove();
                else if (x == 3 )
                        h.printA();

                ifp >> x;
        }

        return 0;
}
