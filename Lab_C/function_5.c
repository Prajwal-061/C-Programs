#include <stdio.h>
int add(int num)
{
    int result = 0, digit;
    while (num > 0)
    {
        digit = num % 10;
        result = result + digit;
        num = num / 10;
    }
    return result;
}
int main()
{
    int num, r;
    printf("enter the number");
    scanf("%d", &num);
    r = add(num);
    printf("the sum is %d", r);
    return 0;
}