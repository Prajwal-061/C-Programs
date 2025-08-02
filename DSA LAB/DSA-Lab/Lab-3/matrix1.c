#include <stdio.h>

void insert_data(int arr[][3], int row, int col) {
    int i, j;
    printf("Enter elements in the matrix: \n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
}

void display(int arr[][3], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int non_zero(int arr[][3], int row, int col) {
    int count = 0;
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void display_upper_triangular(int arr[][3], int row, int col) {
    int i, j;
    printf("Upper Triangular Matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (j >= i) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int row = 3, col = 3;
    int arr[row][col];

    insert_data(arr, row, col);
    display(arr, row, col);

    int value = non_zero(arr, row, col);
    printf("\nThe number of non-zero elements: %d\n", value);

    display_upper_triangular(arr, row, col);

    return 0;
}
