#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the no of rows :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {

            for (j = i; j >= 1; j--)
            {
                printf("%d", j);
            }
            printf("\n");
        }
        else
        {

            for (j = 1; j <= i; j++)
            {
                printf("%d", j);
            }
            printf("\n");
        }
    }
    return 0;
}