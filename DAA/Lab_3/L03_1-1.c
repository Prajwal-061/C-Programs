#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) + 1; // Random number between 1 and 100
    }
}

void insertion_sort(int arr[], int n, int *outer_steps, int *inner_steps)
{
    *outer_steps = 0;
    *inner_steps = 0;

    for (int i = 1; i < n; i++)
    {
        (*outer_steps)++;

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            (*inner_steps)++;
            arr[j + 1] = arr[j];
            j--;
        }

        if (j >= 0)
        {
            (*inner_steps)++; // Final failed comparison
        }

        arr[j + 1] = key;
    }
}

int main()
{
    srand(time(NULL)); // Seed once for random generation

    int sizes[] = {100, 200, 300, 400, 500, 600};
    int n = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fout = fopen("sort_steps_output.txt", "w"); // Overwrite file on each run

    if (fout == NULL)
    {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write column headers
    fprintf(fout, "InputSize OuterSteps InnerSteps\n");

    for (int i = 0; i < n; i++)
    {
        int size = sizes[i];
        int arr[size];
        int outer = 0, inner = 0;

        generate_random_numbers(arr, size);
        insertion_sort(arr, size, &outer, &inner);

        // Write values to file
        fprintf(fout, "%d %d %d\n", size, outer, inner);
    }

    fclose(fout);

    printf(" Sorting complete. Steps written to 'sort_steps_output.txt'\n");

    return 0;
}
