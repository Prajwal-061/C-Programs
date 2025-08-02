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
    int pos;
    printf("enter the position you want to store the value in the array:");
    scanf("%d", &pos);
    if ((pos > n) || (pos < 0))
    {
        printf("invalid position");
        return 1;
    }
    int newvalue;
    printf("enter the new value you want to store :");
    scanf("%d", &newvalue);
    for (i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = newvalue;
    n++;
    printf("array after insertion is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}