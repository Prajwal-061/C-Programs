#include <stdio.h>

int main()
{
    // Assuming an array of size 100, you can change this size as needed
    int n, searchElement;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Taking input for array elements
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d elements:\n", i + 1);
        scanf("%d", &arr[i]);
    }

    // Asking user for the element to search
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    // Searching for the element in the array

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchElement)
        {
            printf("Element %d found\n", searchElement);
            return 0; // Exit the loop once the element is found
        }
    }

    // If the element is not found

    printf("Element %d not found in the array.\n", searchElement);

    return 0; // Exit with success
}
