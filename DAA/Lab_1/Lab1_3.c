#include <stdio.h>

// EXCHANGE: Swap two integers using pointers
void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// ROTATE_RIGHT: Rotate first p2 elements of array to the right by 1
void ROTATE_RIGHT(int *p1, int p2)
{
    // Start from the last of the first p2 elements and move backward
    for (int i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotateCount = 5;

    printf("Before ROTATE: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ROTATE_RIGHT(arr, rotateCount);

    printf("After ROTATE:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
