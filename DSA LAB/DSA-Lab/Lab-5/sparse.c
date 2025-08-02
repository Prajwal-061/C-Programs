#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int row, int col, int value) {
    struct Node *newNode = createNode(row, col, value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Sparse matrix is empty\n");
        return;
    }

    printf("Row\tCol\tValue\n");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols, i, j, value;
    struct Node *head = NULL;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &value);
            if (value != 0) {
                insertNode(&head, i, j, value);
            }
        }
    }

    printf("Sparse Matrix Representation:\n");
    display(head);

    return 0;
}
