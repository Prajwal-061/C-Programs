// Online C compiler to run C program online
#include <stdio.h>

int main()
{
    // Write C code here

    int a[5], i;
    int *q = a;
    printf("the elements in the array are:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &q[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("%u ", (q + i));
    }

    return 0;
}