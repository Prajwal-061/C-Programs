#include <stdio.h>

void print_sparse_matrix(int non_zero, int sparse_matrix[][3]) {
    printf("Sparse Matrix in 3-tuple format:\n");
    printf("R C Element\n");
    for (int i = 0; i <= non_zero; i++) {
        printf("%d %d %d\n", sparse_matrix[i][0], sparse_matrix[i][1], sparse_matrix[i][2]);
    }
}

int main() {
    int rows, cols, non_zero;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    non_zero = 0;
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
               non_zero++;
            }
        }
    }

    int sparse_matrix[non_zero][3];
    sparse_matrix[0][0] = rows;
    sparse_matrix[0][1] = cols;
    sparse_matrix[0][2] = non_zero;
    int non=1;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j] != 0) {
                sparse_matrix[non][0] = i;
                sparse_matrix[non][1] = j;
                sparse_matrix[non][2] = matrix[i][j];
                non++;

            }
        }
    }
    print_sparse_matrix(non_zero, sparse_matrix);

    return 0;

}