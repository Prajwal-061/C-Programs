#include <stdio.h>
int prime(int n)
{
    int i, count = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count = count + 1;
        }
    }
    if (count > 2)
    {
        printf("IT is composite");
    }
    else
    {
        printf("it is prime");
    }
    return 0;
}
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d", &n);
    prime(n);
    return 0;
}