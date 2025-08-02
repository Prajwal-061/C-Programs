#include <stdio.h>

void compare(int *p1, int *p2) {
    if (*p1 > *p2)
        printf("%d is greater than %d\n", *p1, *p2);
    else if (*p1 < *p2)
        printf("%d is less than %d\n", *p1, *p2);
    else
        printf("%d is equal to %d\n", *p1, *p2);
}

int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    int *p1 = &num1, *p2 = &num2;
    compare(p1, p2);
    return 0;
}
