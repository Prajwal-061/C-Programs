#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to check if the brackets are balanced
int isBalanced(char *expr) {
    char stack[MAX];
    int top = -1;

    // Traverse the expression
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            // Push the opening bracket onto the stack
            stack[++top] = expr[i];
        } else {
            // If it's a closing bracket, check if it matches the top of the stack
            if (top == -1) {
                return 0;  // No matching opening bracket
            }

            if ((expr[i] == ')' && stack[top] == '(') ||
                (expr[i] == '}' && stack[top] == '{') ||
                (expr[i] == ']' && stack[top] == '[')) {
                top--;  // Pop the stack
            } else {
                return 0;  // Mismatch found
            }
        }
    }

    // If the stack is empty, then the brackets are balanced
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter the bracket expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
