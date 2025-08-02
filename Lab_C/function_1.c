#include <stdio.h>
int swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("the numbers after swapping is %d and %d", a, b);
    return 0;
}
int main()
{
    int a, b;
    printf("enter the two numbers\n:");
    scanf("%d %d", &a, &b);
    printf("two numbers before swapping is %d  and %d\n", a, b);
    swap(a, b);
    return 0;
}