#include <stdio.h>
int main()
{
    int a = 10, b = 11;
    int *p, *q;
    p = &a;
    q = &b;
    *q = *p;
    printf("%d\n %d\n %d\n", a, *p, *q);
    return 0;
}