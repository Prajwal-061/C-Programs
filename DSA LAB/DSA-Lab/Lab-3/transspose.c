#include <stdio.h>

#define MAX 100   
typedef struct {
    int row;
    int col;
    int value;
} Element;
 
void inputMatrix(Element matrix[], int *count) {
    int numElements;
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);
    
    *count = numElements;
    printf("Enter the elements in the format (row, col, value):\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
} 
void printMatrix(Element matrix[], int count) {
    printf("Row  Col  Value\n");
    for (int i = 0; i < count; i++) {
        printf("%d    %d    %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}
 
void transposeMatrix(Element original[], Element transposed[], int count) {
    for (int i = 0; i < count; i++) {
        transposed[i].row = original[i].col;
        transposed[i].col = original[i].row;
        transposed[i].value = original[i].value;
    }
}

int main() {
    Element matrix[MAX], transposed[MAX];
    int count; 
    inputMatrix(matrix, &count);
     
    printf("Original Matrix:\n");
    printMatrix(matrix, count);
     
    transposeMatrix(matrix, transposed, count);
    
    printf("Transposed Matrix:\n");
    printMatrix(transposed, count);
    
    return 0;
}
