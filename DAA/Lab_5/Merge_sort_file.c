#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

long long comparisons = 0; // Global counter for comparisons

// Merge function
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comparisons++; // Count comparison
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive mergeSort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    FILE *foutput;
    int arr[SIZE];

    // Open file in append mode
    foutput = fopen("mergeResults.txt", "a");
    if (foutput == NULL)
    {
        printf("Error opening output file!\n");
        return 1;
    }

    srand(time(0)); // Seed for randomness

    // Step 1: Generate random numbers
    printf("Randomly Generated Numbers:\n");
    fprintf(foutput, "\n\n--- New Run ---\n");
    fprintf(foutput, "Random Numbers:\n");

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000; // Random number (0 - 999)
        printf("%d ", arr[i]);
        fprintf(foutput, "%d ", arr[i]);
    }
    printf("\n\n");
    fprintf(foutput, "\n");

    // Step 2: Sort using mergeSort
    comparisons = 0; // reset counter
    mergeSort(arr, 0, SIZE - 1);

    // Step 3: Display and Save results
    printf("Sorted Array:\n");
    fprintf(foutput, "Sorted Array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
        fprintf(foutput, "%d ", arr[i]);
    }

    printf("\n\nTotal Comparisons: %lld\n", comparisons);
    fprintf(foutput, "\nTotal Comparisons: %lld\n", comparisons);

    fclose(foutput);

    printf("\nResults saved in mergeResults.txt (appended).\n");

    return 0;
}
