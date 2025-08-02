#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node *head)
{
    int count = 0;
    struct node *temp = head;
    printf("Linked list:\n");
    while (temp != NULL)
    {
        printf(" %p<-%d->%p  ", temp->prev, temp->data, temp->next);
        temp = temp->next;
        count++;
    }
    printf("\n the total nodes are %d", count);
}

struct node *insert_at_specific(struct node *head, int n)
{
    struct node *newnode, *temp;
    int pos, i = 1;
    printf("enter the position to enter the node:");
    scanf("%d", &pos);
    if (pos > n || pos < 0)
    {
        printf("invalid postion");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("memory allocation failed");
        }
    }
    printf("enter the data for the new node:");
    scanf("%d", &newnode->data);
    temp = head;
    newnode->next = NULL;
    newnode->prev = NULL;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

    display(head);

    return 0;
}

int main()
{
    int i, n, count = 0;
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
        newnode->prev = NULL;
        if (head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
        }
        temp = newnode;
    }

    insert_at_specific(head, n);

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
