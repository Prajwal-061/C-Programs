#include <stdio.h>
int add(int a, int b)
{
    int sum = a + b;
    return sum;
}
int product(int a, int b)
{
    int mul = a * b;
    return mul;
}
int subtract(int a, int b)
{
    int sub = a - b;
    return sub;
}
int div(int a, int b)
{
    int d = a / b;
    return d;
}
int modulus(int a, int b)
{
    int mod = a % b;
    return mod;
}
int main()
{
    int a, b, option;

    printf("enter the two numbers:");
    scanf("%d %d", &a, &b);
    printf("the operation you want to perform:\n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.Modulus\n");
    printf("enter the option:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Addition is %d", add(a, b));
        break;
    case 2:
        printf("Subtraction is %d", subtract(a, b));
        break;
    case 3:
        printf("product is %d", product(a, b));
        break;
    case 4:
        printf("division is %d", div(a, b));
        break;
    case 5:
        printf("Modulus is %d", modulus(a, b));
        break;
    default:
        printf("invalid option\n");
    }
    return 0;
}