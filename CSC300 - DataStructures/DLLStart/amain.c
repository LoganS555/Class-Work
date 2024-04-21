#include "dll.h"

int main()
{
        struct dllheader *A, *B, *C;
        struct lnode *tmp;
        int i, x;

        A = makelist();
        B = makelist();
        C = makelist();


        for (i = 0; i < 3; ++i)
        {
                x = rand() % 25 + 1;
                printf("Added: %d\n", x);
                insertFront( A, x );
                insertBack( B, x );
        }

        printerF( A );
        printerR( B );
        printerF( B );

        tmp = A->begin;
        insertAfter(A,88,tmp);
        printerF( A );

        return 0;
}
