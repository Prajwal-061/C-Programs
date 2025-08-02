#include <stdio.h>
int main()
{
    int i, j, n;
    int num = 1;
    printf("enter the no of rows :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= i; j++)
        {
            printf("%d", num);
            num++;
        }
        printf("\n");
    }
}