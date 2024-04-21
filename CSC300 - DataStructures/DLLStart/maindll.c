#include "dll.h"

int main()
{
        struct dllheader *L;
        int i, x, y;

        L = makelist();

        for (i = 0; i < 5; ++i)
        {
                x = rand() % 25 + 1;
                y = rand() % 25 + 1;
                printf("-- Adding -- %d\n", x);
                printf("-- Adding -- %d\n", y);
                insertFront( L, x );
                insertBack( L, y );
                printerF( L );
                printerR( L );
        }

        return 0;
}
