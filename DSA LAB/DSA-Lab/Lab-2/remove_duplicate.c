#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;
    
    int j = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;  
}

int main() {
    int size, i;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int arr[size];
    
    for (i = 0; i < size; i++) {
        printf("Enter value at %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int newSize = removeDuplicates(arr, size);
    
    printf("Array after removing duplicates: \n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
