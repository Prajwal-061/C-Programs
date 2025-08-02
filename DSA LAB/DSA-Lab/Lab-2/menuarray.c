#include <stdio.h>

void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void delete(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int linear_search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], size, choice, pos, value;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Linear Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, size);
                break;
            case 2:
                printf("Enter position to insert (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &size, pos, value);
                break;
            case 3:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = linear_search(arr, size, value);
                if (pos == -1) {
                    printf("Value not found in the array.\n");
                } else {
                    printf("Value found at position %d.\n", pos);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
