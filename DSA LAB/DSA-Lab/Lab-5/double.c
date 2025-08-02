#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;

void create() {
    int data, addMore;
    struct Node *newNode, *temp;

    do {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }

        printf("Want to add more? (Yes=1 / No=0): ");
        scanf("%d", &addMore);
    } while (addMore == 1);

    printf("List created successfully\n");
}

// Function to insert a node at a specific position
void insert() {
    int data, pos, i = 1;
    struct Node *newNode, *temp;

    printf("Enter position to insert (starting from 1): ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &data);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = start;
        if (start != NULL) {
            start->prev = newNode;
        }
        start = newNode;
    } else {
        temp = start;
        while (temp != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted successfully\n");
}

// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node at a given position
void deleteNode() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    int pos, i = 1;
    struct Node *temp = start;

    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);

    if (pos == 1) {
        start = temp->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        free(temp);
        printf("Node deleted successfully\n");
        return;
    }

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted successfully\n");
}

int main() {
    int choice;

    do {
        printf("\n********* Double Linked List ********\n");
        printf("1. Create List\n2. Insert at Position\n3. Display\n4. Delete\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                display();
                break;
            case 4:
                deleteNode();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 5);

    return 0;
}
