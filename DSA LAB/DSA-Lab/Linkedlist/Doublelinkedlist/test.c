#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function with the first element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;          // Index for elements greater than the pivot
    int j = high;         // Index for elements smaller than the pivot

    while (i <= j)
    {
        // Find an element larger than the pivot
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        // Find an element smaller than the pivot
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        // If i is still less than j, swap elements at i and j
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    // Place pivot in its correct position by swapping with j
    swap(&arr[low], &arr[j]);
    return j; // Return the pivot index
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    displayArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    displayArray(arr, n);

    return 0;
}
