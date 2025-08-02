#include <stdio.h>
int main()
{
    int n, largest, second, i;
    printf("enter the values you want to store in the arrays:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("enter the values %d:", i + 1);
        scanf("%d", &a[i]);
    }
    if (a[0] > a[1])
    {
        second = a[1];
        largest = a[0];
    }
    else
    {
        largest = a[1];
        second = a[0];
    }
    for (i = 2; i < n; i++)
    {
        if (a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if ((a[i] > second) && (a[i] != largest))
        {
            second = a[i];
        }
    }
    printf("largest element is %d and second largest element is %d", largest, second);
    return 0;
}