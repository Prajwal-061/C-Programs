#include <stdio.h>
int fact(int n)
{
    int result = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        result = result * i;
    }
    // printf("the factorial is %d", result);
    return result;
}
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d", &n);
    int r = fact(n);
    printf("the factorial is %d", r);

    return 0;
}
