
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    int count = 0;
    struct node *temp = head;
    printf("\nLinked list:\n");
    while (temp != NULL)
    {
        printf("%d->%p  ", temp->data, temp->next);
        temp = temp->next;
        count++;
    }
    printf("\n the total number of nodes are:%d", count);
}
struct node *delete_at_specific(struct node *head, int n)
{
    int pos;
    int i = 1;
    struct node *newnode, *temp, *prevnode, *nextnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
    }
    printf("enter the position to delete the node:\n");
    scanf("%d", &pos);
    if (pos > n || pos < 0)
    {
        printf("invalid position");
    }
    else
    {

        temp = head;
        while (i < pos)
        {
            prevnode = temp;
            temp = temp->next;

            i++;
        }
        prevnode->next = temp->next;

        free(temp);
    }

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
    delete_at_specific(head, n);
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
