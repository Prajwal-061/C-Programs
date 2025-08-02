#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the no of rows :");
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= (i * 2) - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}