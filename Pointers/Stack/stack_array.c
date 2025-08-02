#include <stdio.h>

int stack[5];
int top = -1;

void push()
{
    int x;
    printf("Enter the data to enter: ");
    scanf("%d", &x);
    if (top == 5 - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed into the stack\n", x);
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d is the deleted item from the stack\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    do
    {
        printf("\nEnter choice:\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter choice for operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 0);

    return 0;
}
