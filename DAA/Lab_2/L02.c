#include <stdio.h>
#include <stdlib.h>

// Recursive function to convert a decimal number to binary and write it to file
void decimalToBinary(int num, FILE *destFile)
{
    if (num > 1)
        decimalToBinary(num / 2, destFile);
    fprintf(destFile, "%d", num % 2);
    printf("%d", num % 2);
}

int main()
{
    FILE *srcFile, *destFile;
    int n, count = 0, number;

    // Open source file for reading
    srcFile = fopen("decimal.txt", "r");
    if (srcFile == NULL)
    {
        printf("Error opening source file.\n");
        return 1;
    }

    // Open destination file for writing binary numbers
    destFile = fopen("binary.txt", "w");
    if (destFile == NULL)
    {
        printf("Error opening destination file.\n");
        fclose(srcFile);
        return 1;
    }

    printf("Enter how many numbers you want to convert: ");
    scanf("%d", &n);

    // Read and convert numbers
    while (count < n && fscanf(srcFile, "%d", &number) == 1)
    {
        fprintf(destFile, "Decimal: %d -> Binary: ", number);
        printf("Decimal: %d -> Binary: ", number);
        if (number == 0)
        {
            fprintf(destFile, "0");
            printf("0");
        }
        else
        {
            decimalToBinary(number, destFile);
        }
        fprintf(destFile, "\n");
        printf("\n");
        count++;
    }

    printf("Conversion complete. Check 'binary.txt' for output.\n");

    fclose(srcFile);
    fclose(destFile);
    return 0;
}
