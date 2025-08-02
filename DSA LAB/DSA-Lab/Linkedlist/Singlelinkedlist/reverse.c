
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
struct node *reverse(struct node *head, int n)
{

    struct node *temp, *prevnode, *nextnode;
    prevnode = NULL;
    nextnode = temp = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    head = prevnode;
    return head;
    // display(head);
    //  return temp;
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

    printf("the original linked list is:\n");
    display(head);

    head = reverse(head, n);

    printf("reversed linked list is:\n");

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
