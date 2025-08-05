#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200

void generate_random_file(const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    srand(time(NULL)); // Seed random once

    for (int i = 0; i < SIZE; i++)
    {
        int a = (rand() % 100) + 1; // Random between 1 and 100
        fprintf(f, "%d ", a);
    }

    fclose(f);
}

void read_numbers_from_file(const char *filename, int arr[])
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    for (int i = 0; i < SIZE; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }

    fclose(f);
}

void insertion_sort(int arr[], int n, int *outer_steps, int *inner_steps)
{
    *outer_steps = 0;
    *inner_steps = 0;

    for (int i = 1; i < n; i++)
    {
        (*outer_steps)++; // Count each outer loop iteration

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            (*inner_steps)++; // Each comparison + shift
            arr[j + 1] = arr[j];
            j--;
        }

        // One final comparison that fails (when while exits)
        if (j >= 0)
        {
            (*inner_steps)++;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    const char *filename = "input_100.txt";
    int arr[SIZE];
    int outer_steps, inner_steps;

    generate_random_file(filename);
    printf(" Random numbers written to '%s'.\n", filename);

    read_numbers_from_file(filename, arr);

    insertion_sort(arr, SIZE, &outer_steps, &inner_steps);

    printf("\nSorted Numbers:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nOuter loop steps (passes): %d", outer_steps);
    printf("\n Inner loop steps (comparisons + shifts): %d\n", inner_steps);

    return 0;
}
