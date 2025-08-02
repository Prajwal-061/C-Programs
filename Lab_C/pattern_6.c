#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the no of rows :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= (i * 2) - 1; k++)
        {
            printf("%d", k + 1);
        }
        printf("\n");
    }
    return 0;
}