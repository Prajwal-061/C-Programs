#include <stdio.h>
#include <stdlib.h>

// Define a node for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Initialize front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Check if the deque is empty
int isEmpty() {
    return front == NULL;
}

// Insert an element at the front
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (isEmpty()) {
        rear = newNode;  // If the deque is empty, rear is also the new node
    } else {
        front->prev = newNode;
    }

    front = newNode;
    printf("%d inserted at front\n", value);
}

// Insert an element at the rear
void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (isEmpty()) {
        front = newNode;  // If the deque is empty, front is also the new node
    } else {
        rear->next = newNode;
    }

    rear = newNode;
    printf("%d inserted at rear\n", value);
}

// Delete an element from the front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty, nothing to delete!\n");
        return;
    }

    struct Node* temp = front;
    printf("%d deleted from front\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;  // If deque becomes empty
    } else {
        front->prev = NULL;
    }

    free(temp);
}

// Delete an element from the rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty, nothing to delete!\n");
        return;
    }

    struct Node* temp = rear;
    printf("%d deleted from rear\n", rear->data);

    rear = rear->prev;

    if (rear == NULL) {
        front = NULL;  // If deque becomes empty
    } else {
        rear->next = NULL;
    }

    free(temp);
}

// Display the deque from front to rear
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
