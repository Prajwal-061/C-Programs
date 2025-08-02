#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i, n, count = 0;
    struct node *head, *newnode, *temp;
    head = NULL;
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
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }

    printf("Linked list:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d->%u  ", temp->data, temp->next);
        temp = temp->next;
        count++;
    }
    printf("\n Number of nodes are %d", count);
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
