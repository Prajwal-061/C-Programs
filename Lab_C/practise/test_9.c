#include <stdio.h>
int main()
{
    int i, j, n;
    printf("enter the no of rows :");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (j = i; j >= 1; j--)
        {
            printf(" %c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}