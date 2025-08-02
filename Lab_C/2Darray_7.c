#include <stdio.h>

int main()
{
    int rows, cols, i, j;
    // Get the number of rows and columns
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Check if it's a square matrix
    if (rows != cols)
    {
        printf("Not a square matrix. Identity matrices are square.\n");
        return 0;
    }

    // Initialize a flag to check if it's an identity matrix
    int isIdentity = 1;

    // Input the matrix elements
    int matrix[rows][cols];
    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("the value of matrxi A is\n");
    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Check if it's an identity matrix
    int identity = 1;
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                identity = 0;
                break;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                identity = 0;
                break;
            }
        }
    }
    if (identity)
    {
        printf("it is identity");
    }
    else
    {
        printf("not identity");
    }

    return 0;
}
