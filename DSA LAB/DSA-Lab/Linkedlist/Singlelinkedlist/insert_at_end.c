
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *temp = head;
    printf("Linked list:\n");
    while (temp != NULL)
    {
        printf("%d->%p  ", temp->data, temp->next);
        temp = temp->next;
    }
}
struct node *insert_at_end(struct node *head)
{

    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
    }
    printf("\nEnter the data you want to insert at the end:");
    scanf("%d", &newnode->data);
    temp = head;
    newnode->next = NULL;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    display(head);
    // return temp;
}

int main()
{
    int i, n;
    struct node *head = NULL, *newnode, *temp;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory Allocation failed");
        }
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }
    insert_at_end(head);
    // display(head);

    // free the allocated memory
    temp = head;
    while (temp != NULL)
    {
        newnode = temp;
        temp = temp->next;
        free(newnode);
    }
    return 0;
}
