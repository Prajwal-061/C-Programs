#include <stdio.h>
int fibbo(int n)
{
    int i, t1 = 0, t2 = 1, nt;
    for (i = 3; i <= n; i++)
    {
        nt = t1 + t2;
        t1 = t2;
        t2 = nt;
    }
    return nt;
}
int main()
{
    int n, t1 = 0, t2 = 1;
    printf("enter the number of term:");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("your term is %d", t1);
    }
    if (n == 2)
    {
        printf("your term is %d", t2);
    }
    if (n > 2)
    {
        printf("your term is %d", fibbo(n));
    }
    return 0;
}