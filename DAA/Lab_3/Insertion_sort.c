#include <stdio.h>

int main()
{
    int n, i, j, key;
    int outer_steps = 0, inner_steps = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 1; i < n; i++)
    {
        outer_steps++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            inner_steps++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Outer loop steps: %d\n", outer_steps);
    printf("Inner loop steps: %d\n", inner_steps);
    return 0;
}
