#include <stdio.h>
#include <stdlib.h>

int main() // void main() is not recommended in modern C.
{
    int *a, x, i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d in the array: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the element that should be deleted from the array: ");
    scanf("%d", &x);

    // Find and delete the element by shifting the rest of the array
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] != x)
        {
            a[j] = a[i];
            j++;
        }
    }

    // j now contains the new size of the array after deletion
    n = j;

    printf("The updated array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    free(a); // Free the allocated memory
    return 0;
}
