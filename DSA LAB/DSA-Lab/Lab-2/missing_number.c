#include <stdio.h>

int findFirstMissingPositive(int arr[], int size) {
    int present[size + 1];
    
    for (int i = 0; i <= size; i++) {
        present[i] = 0;
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] <= size) {
            present[arr[i]] = 1;
        }
    }
    
    for (int i = 1; i <= size; i++) {
        if (present[i] == 0) {
            return i;
        }
    }
    
    return size + 1;
}

int main() {
    int size;
    
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    for (int i = 0; i < size; i++) {
        printf("Enter value at %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int result = findFirstMissingPositive(arr, size);
    printf("The first missing positive number is: %d\n", result);
    
    return 0;
}
