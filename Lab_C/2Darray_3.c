#include <stdio.h>
int main()
{
    int i, j;
    int a[3][3], b[3][3];
    printf("enter elements for first matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("enter the values for  a%d%d:", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter elements for second matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("enter the values for  b%d%d:", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == b[i][j])
            {
                printf("equal");
                return 0;
            }
        }
    }

    printf("not equal");
    return 0;
}
