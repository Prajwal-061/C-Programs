#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the no of rows :");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i == 1 || i == n)
        {
            for (j = 1; j <= n; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (j = 1; j <= n; j++)
            {
                if (j == 1 || j == n)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}