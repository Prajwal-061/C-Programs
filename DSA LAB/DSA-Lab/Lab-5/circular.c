#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(struct Node* start, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = start;

    if (start == NULL) {
        newNode->next = newNode;
        start = newNode;
    } else {
        struct Node* temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = start;
    }
    return start;
}

struct Node* display(struct Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    struct Node* temp = start;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
    return start;
}

int main() {
    struct Node* start = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        start = create(start, data);
    }

    printf("Circular Linked List: ");
    start = display(start);

    return 0;
}