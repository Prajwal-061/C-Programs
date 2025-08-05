#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int n, i, j, count, maxCount = 0;
    int mostRepeating;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int)); // to mark visited duplicates

    file = fopen("input_1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    // Print array
    printf("The content of the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int duplicateCount = 0;

    // Count duplicates and find most repeating element
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            continue;

        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        if (count > 1)
        {
            duplicateCount++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostRepeating = arr[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicateCount);
    printf("The most repeating element in the array = %d\n", mostRepeating);

    free(arr);
    free(visited);

    return 0;
}
