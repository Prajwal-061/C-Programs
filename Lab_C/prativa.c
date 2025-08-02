#include <stdio.h>
int main()
{
    int n, i, s;
    int even = 0;
    int odd = 0;
    printf("enter the starting range:");
    scanf("%d", &s);
    printf("enter the ending range:");
    scanf("%d", &n);
    for (i = s; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            even = even + i;
        }
        else
        {
            odd = odd + i;
        }
    }
    printf("the sum of all the even numbers is %d\n", even);
    printf("the sum of all the odd numbers is %d\n", odd);
}