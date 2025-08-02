#include <stdio.h>
#include <limits.h>  // For INT_MIN

#define MAX 100  // Define the maximum size of the stack

// Define two stacks using arrays
int mainStack[MAX];
int maxStack[MAX];
int topMain = -1;  // Top of the main stack
int topMax = -1;   // Top of the max stack

// Function to push an element onto the main stack and max stack
void push(int x) {
    if (topMain == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", x);
        return;
    }
    
    mainStack[++topMain] = x;  // Push onto the main stack
    
    // If the max stack is empty or x is greater than or equal to the current max
    if (topMax == -1 || x >= maxStack[topMax]) {
        maxStack[++topMax] = x;  // Push onto the max stack
    }
}

// Function to pop an element from the main stack and max stack
void pop() {
    if (topMain == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    
    int popped = mainStack[topMain--];  // Pop from the main stack
    
    // If the popped element is the same as the top of the max stack, pop from the max stack too
    if (popped == maxStack[topMax]) {
        topMax--;
    }
}

// Function to get the maximum element from the stack
int getMax() {
    if (topMax == -1) {
        printf("Stack is empty. No maximum element.\n");
        return INT_MIN;  // Return the smallest possible integer if the stack is empty
    }
    
    return maxStack[topMax];  // Return the top element of the max stack
}

// Main function
int main() {
    push(10);
    push(20);
    push(5);
    push(30);
    
    printf("Maximum element: %d\n", getMax());  // Should print 30
    
    pop();  // Remove 30
    
    printf("Maximum element after pop: %d\n", getMax());  // Should print 20
    
    pop();  // Remove 5
    pop();  // Remove 20
    
    printf("Maximum element after two more pops: %d\n", getMax());  // Should print 10
    
    return 0;
}
