#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    int n, i;
    int *arr;

    file = fopen("C:\\Users\\KIIT0001\\Desktop\\DAA\\Lab_1\\input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("The array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (n < 2)
    {
        printf("Array does not have enough elements for a second smallest number.\n");
    }
    else
    {
        int min1 = arr[0], min2;
        min2 = __INT_MAX__;
        for (i = 1; i < n; i++)
        {
            if (arr[i] < min1)
            {
                min2 = min1;
                min1 = arr[i];
            }
            else if (arr[i] > min1 && arr[i] < min2)
            {
                min2 = arr[i];
            }
        }
        if (min2 == __INT_MAX__)
        {
            printf("No second smallest number (all elements are equal).\n");
        }
        else
        {
            printf("Second smallest number: %d\n", min2);
        }

        int max1 = arr[0], max2;
        max2 = -__INT_MAX__ - 1;
        for (i = 1; i < n; i++)
        {
            if (arr[i] > max1)
            {
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] < max1 && arr[i] > max2)
            {
                max2 = arr[i];
            }
        }
        if (max2 == -__INT_MAX__ - 1)
        {
            printf("No second largest number (all elements are equal).\n");
        }
        else
        {
            printf("Second largest number: %d\n", max2);
        }
    }
}
