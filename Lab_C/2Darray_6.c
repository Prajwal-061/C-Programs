#include <stdio.h>
int main()
{
    int i, j;
    int a[3][3], sum = 0;
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
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                sum = sum + a[i][j];
            }
        }
    }
    printf("the sum is %d", sum);

    return 0;
}