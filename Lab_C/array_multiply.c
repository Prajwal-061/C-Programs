#include <stdio.h>
int main()
{
    int i, n;
    printf("enter total no of values you want to store in the array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("enter the numbers %d", i + 1);
        scanf("%d", &a[i]);
    }
    int product = 1;
    for (i = 0; i < n; i++)
    {
        product = product * a[i];
    }
    printf("the product of the array element is %d\n", product);

    // int largest = a[0];
    // for (i = 0; i < n; i++)
    // {
    //     if (a[i] > largest)
    //     {
    //         largest = a[i];
    //     }
    // }
    // printf("the largest content in the array is %d\n", largest);
    return 0;
}