#include <stdio.h>
int main()
{
    int i, n;
    printf("enter total no of values you want to store in the array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("enter the numbers %d", i + 1);
        scanf("%d", &a[i]);
    }
    printf("even elements are\n");
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            printf("%d\n", a[i]);
        }
    }
    printf("odd elements are\n");
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == !0)
        {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}