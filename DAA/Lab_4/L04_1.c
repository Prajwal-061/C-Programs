#include <stdio.h>

int find_min(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int min_rest = find_min(arr, n - 1);
    return (arr[n - 1] < min_rest) ? arr[n - 1] : min_rest;
}

int find_max(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int max_rest = find_max(arr, n - 1);
    return (arr[n - 1] > max_rest) ? arr[n - 1] : max_rest;
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = find_min(arr, n);
    int max = find_max(arr, n);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    return 0;
}
