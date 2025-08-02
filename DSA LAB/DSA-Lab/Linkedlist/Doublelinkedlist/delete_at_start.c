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

struct node *delete_at_start(struct node *head)
{
    struct node *newnode, *temp;
    // newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    free(temp);
    return head;
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

    head = delete_at_start(head);
    display(head);
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
