#include <stdio.h>

int main() {
    int n, i, j, sum = 0;

    // Input the size of the matrix (n x n)
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of elements above the main diagonal
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            sum += matrix[i][j];
        }
    }

    // Output the sum of elements above the main diagonal
    printf("Sum of the elements above the main diagonal: %d\n", sum);

    return 0;
}
