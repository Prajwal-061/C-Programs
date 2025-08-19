#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

// Check if file already exists
int fileExists(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f)
    {
        fclose(f);
        return 1;
    }
    return 0;
}

int main()
{
    int arr[SIZE];
    char filename[] = "mergeResults1.txt";
    FILE *f;

    if (!fileExists(filename))
    {
        // ===== FIRST RUN =====
        srand(time(0));
        printf("Randomly Generated Numbers:\n");

        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = rand() % 1000;
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        comparisons = 0;
        mergeSort(arr, 0, SIZE - 1);

        // Save to file
        f = fopen(filename, "w"); // create new file
        fprintf(f, "--- Run 1 ---\n");
        fprintf(f, "Random Numbers:\n");
        for (int i = 0; i < SIZE; i++)
            fprintf(f, "%d ", arr[i]);
        fprintf(f, "\nSorted Array:\n");
        for (int i = 0; i < SIZE; i++)
            fprintf(f, "%d ", arr[i]);
        fprintf(f, "\nTotal Comparisons: %lld\n", comparisons);
        fclose(f);

        printf("Sorted Array:\n");
        for (int i = 0; i < SIZE; i++)
            printf("%d ", arr[i]);
        printf("\n\nTotal Comparisons: %lld\n", comparisons);
        printf("Results saved in %s\n", filename);
    }
    else
    {
        // ===== NEXT RUNS =====
        // Read last sorted array from file
        f = fopen(filename, "r");
        if (f == NULL)
        {
            printf("Error opening %s\n", filename);
            return 1;
        }

        char line[10000];
        long pos, lastSortedPos = -1;

        while (!feof(f))
        {
            pos = ftell(f);
            if (fgets(line, sizeof(line), f))
            {
                if (strstr(line, "Sorted Array:"))
                {
                    lastSortedPos = pos;
                }
            }
        }

        if (lastSortedPos == -1)
        {
            printf("No sorted array found in file!\n");
            fclose(f);
            return 1;
        }

        fseek(f, lastSortedPos, SEEK_SET);
        fgets(line, sizeof(line), f); // skip "Sorted Array:"
        for (int i = 0; i < SIZE; i++)
        {
            fscanf(f, "%d", &arr[i]);
        }
        fclose(f);

        printf("Using previously sorted array as input:\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        comparisons = 0;
        mergeSort(arr, 0, SIZE - 1);

        // Append to file
        f = fopen(filename, "a");
        fprintf(f, "\n--- New Run ---\n");
        fprintf(f, "Input was previous sorted array\n");
        fprintf(f, "Sorted Array:\n");
        for (int i = 0; i < SIZE; i++)
            fprintf(f, "%d ", arr[i]);
        fprintf(f, "\nTotal Comparisons: %lld\n", comparisons);
        fclose(f);

        printf("Sorted Array:\n");
        for (int i = 0; i < SIZE; i++)
            printf("%d ", arr[i]);
        printf("\n\nTotal Comparisons: %lld\n", comparisons);
        printf("Results appended in %s\n", filename);
    }

    return 0;
}
