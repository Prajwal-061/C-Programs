#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top=-1;

void push(){
    int n;
    if(top==MAXSIZE-1){
        printf("\n Stack Overflow\n");
    }else{
        printf("Enter element:  ");
        scanf("%d",&n); 
        top++;
        stack[top]=n;
    }
}

void display(){
    int i;
    if(top==-1){
        printf("Stack empty\n");
    }else{
        printf("Elements: ");
        for(i=top; i>=0; i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
        printf("\n");
    }
}

int isEmpty(){
    if(top==-1){
        printf("Stack is empty\n");
        return 1;
    }else{
        printf("Stack is non-empty\n");
        return 0;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is empty\n");
    }else{
       int n=stack[top];
        printf("Popped Out %d",n);
        top--;
    }
}


void main(){
    int choice;
    do{
        printf("-----STACK-----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. isEmpty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();break;
            case 2: pop();break;
            case 3: display();break;
            case 4: isEmpty();break;
            case 5: printf("Exitting..\n");break;
            default: printf("\nInvalid Choice\n");
        }
    }while(choice != 4);
} 