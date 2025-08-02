#include <stdio.h>
int main()
{
    int i, j;
    int a[2][2], b[2][2], c[2][2];
    printf("enter elements for first matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("enter the values for  a%d%d:", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter elements for second matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("enter the values for  b%d%d:", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    int equal = 1;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
        printf("\n");
    }

    printf("tne sum of matrix is\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
