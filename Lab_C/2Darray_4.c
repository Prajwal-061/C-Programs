#include <stdio.h>
int main()
{
    int i, j;
    int a[3][3], c[3][3];
    printf("enter elements for first matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("enter the values for  a%d%d:", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("the value of matrxi A is\n");
    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("tne transpose of matrix A is\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
