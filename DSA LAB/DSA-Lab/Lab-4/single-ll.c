#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}; 

struct node *start = NULL, *new, *temp, *ptr,*post;

int create() {
    int n, add;

    new = (struct node*)malloc(sizeof(struct node));

    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter data: ");
    scanf("%d", &n);  
    new->data = n;
    new->next = NULL;
    start = new;
    temp = new;

    printf("Want to add More?? (y/Y=1 && n/N=0) \n");
    scanf("%d", &add); 

    while (add == 1) {
        new = (struct node*)malloc(sizeof(struct node));
        
        if (new == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter data: ");
        scanf("%d", &n); 
        new->data = n;
        new->next = NULL;
        temp->next = new;
        temp = new;

        printf("Want to add More?? (y/Y=1 && n/N=0) \n");
        scanf("%d", &add); 
    }  
}

void traverse() {
    temp = start;
    if (start == NULL) {
        printf("\nUnderflow\n");
    } else {
        printf("Linked List: \n");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int count_list(){
    temp=start;
    int count=0;
    if(start == NULL){
        return 0;
    } else {
        while(temp != NULL){
            count++;
            temp=temp->next;
        }
        printf("No. of nodes = %d\n",count);
        return count;
    }
}

void insert() {
    int pos, n;
    temp = start;
    int count = count_list();

    if (start == NULL) {
        printf("\nUnderflow\n");
    } else {
        printf("\n");
        printf("Enter Position to Insert data: ");
        scanf("%d", &pos);

        if (pos < 1 || pos > (count + 1)) {
            printf("\nInvalid Position\n");
        } else {
            if (pos == 1) {
                // Insert at the beginning
                new = (struct node*)malloc(sizeof(struct node));
                if (new == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                printf("Enter data: ");
                scanf("%d", &n);
                new->data = n;
                new->next = start;
                start = new;
            } else if (pos == (count + 1)) {
                // Insert at the end
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                new = (struct node*)malloc(sizeof(struct node));
                if (new == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                printf("Enter data: ");
                scanf("%d", &n);
                new->data = n;
                new->next = NULL;
                temp->next = new;
            } else {
                // Insert in the middle
                int i = 1;
                while (i < pos - 1) {
                    temp = temp->next;
                    i++;
                }
                new = (struct node*)malloc(sizeof(struct node));
                if (new == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                printf("Enter data: ");
                scanf("%d", &n);
                new->data = n;
                new->next = temp->next;
                temp->next = new;
            }
        }
    }
}

void delete(){
    int pos;
    int count = count_list();
    temp=start;

    if(start == NULL){
        printf("\nUnderFlow\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > count){
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1){ // delete first
        start = start->next;
        free(temp);
    } else {
        for(int i = 1; i < pos; i++){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
    }
}

void search(){
    int key;
    temp=start;
    int found = 0;

    if (start == NULL) {
        printf("\nUnderflow\n");
    } else {
        printf("Enter key to search: ");
        scanf("%d",&key);
        while (temp != NULL) {
             if(temp->data == key){
                found = 1;
                break;
             }
             temp = temp->next;
        }
        if(found == 1){
            printf("Element found!!!\n");
        } else {
            printf("Element Not Found\n");
        }
    }
}

void sort() {
    if (start == NULL) {
        printf("\nUnderflow\n");
        return;
    }

    struct node *i, *j;
    int tempData;

    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data between i and j
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("\nLinked list sorted in ascending order.\n");
}

void reverse() {
    struct node *prev = NULL, *current = start, *next = NULL;

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    start = prev;   
    printf("\nLinked list reversed.\n");
}


int main() {
    int choice;
    
    do {
        printf("\n********** Singly Linked List **********\n");
        printf("1. Create\n");
        printf("2. Insert at any position\n");
        printf("3. Delete at any position\n");
        printf("4. Count Nodes\n");
        printf("5. Traverse the LinkedList\n");
        printf("6. Search the LinkedList\n");
        printf("7. Sort the LinkedList\n");
        printf("8. Reverse the LinkedList\n");
        printf("9. Exit\n");
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
                delete(); 
                break;
            case 4:
                count_list(); 
                break;
            case 5:
                traverse(); 
                break;
            case 6:
                search(); 
                break;
            case 7:
            sort();
            break;
            case 8:
            reverse();
            break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
