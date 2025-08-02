#include <stdio.h>
int main()
{
    int i, n, count = 0;
    printf("enter total no of values you want to store in the array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("enter the numbers %d:", i + 1);
        scanf("%d", &a[i]);
    }
    printf("duplicate elements in the array are\n");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                printf("duplicate elements are: %d\n", a[i]);
                count = count + 1;
            }
        }
    }
    printf("%d", count);
    return 0;
}
