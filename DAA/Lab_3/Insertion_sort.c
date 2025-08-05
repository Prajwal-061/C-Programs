#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, key;
    int outer_steps = 0, inner_steps = 0;

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
