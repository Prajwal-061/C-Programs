// this is undefined behavior due to derefrencing an uninitialized pointer.
#include <stdio.h>
int main()
{

    int a = 10, b = 11;
    int *p, *q;
    p = &a;
    *q = *p;
    printf("%d", *q);

    return 0;
}