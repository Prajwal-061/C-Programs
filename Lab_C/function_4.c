#include <stdio.h>
int fibbo(int n)
{
    int i, t1 = 0, t2 = 1, nt;
    printf("%d %d ", t1, t2);
    if (n == 1)
    {
        printf("%d", t1);
    }
    if (n == 2)
    {
        printf("%d", t2);
    }
    if (n > 2)
    {
        for (i = 3; i <= n; i++)
        {
            nt = t1 + t2;
            t1 = t2;
            t2 = nt;
            printf("%d ", nt);
        }
    }

    return 0;
}
int main()
{
    int n, t1 = 0, t2 = 1, i, nt;
    printf("enter the number of term:");
    scanf("%d", &n);
    fibbo(n);

    return 0;
}