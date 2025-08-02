#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;
    printf("a=%d\n", a);
    printf("a=%d\n", *p);
    printf("a=%d\n", **q);
    printf("%x\n", p);
    printf("%x\n", q);
}