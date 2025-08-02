#include <stdio.h>

int main()
{
    int n, i, j;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read elements of the array
    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print unique elements
    printf("Unique elements in the array are: ");
    for (i = 0; i < n; i++)
    {
        // Check if arr[i] is unique
        int isUnique = 1;
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isUnique = 0;
                break;
            }
        }

        // If unique, print the element
        if (isUnique)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
