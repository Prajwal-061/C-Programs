#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2);
void multiplyComplex(Complex *c1, Complex *c2, Complex *result);
void printComplex(Complex c);

int main() {
    Complex c1, c2, result;
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;  
        }

        printf("Enter the real and imaginary parts of the first complex number (e.g., 1 2): ");
        scanf("%f %f", &c1.real, &c1.imag);
        printf("Enter the real and imaginary parts of the second complex number (e.g., 3 4): ");
        scanf("%f %f", &c2.real, &c2.imag);

        if (choice == 1) {
            result = addComplex(c1, c2);
            printf("Result of addition: ");
            printComplex(result);
        } else if (choice == 2) {
            multiplyComplex(&c1, &c2, &result);
            printf("Result of multiplication: ");
            printComplex(result);
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void multiplyComplex(Complex *c1, Complex *c2, Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

void printComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}
