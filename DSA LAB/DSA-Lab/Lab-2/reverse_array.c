#include<stdio.h>

void reverse(int arr[], int start, int end){
   if (start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, start + 1, end - 1);
}

int main(){
    int size,i;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    int arr[size];

    for(i=0;i<size; i++){
        printf("Enter value at %d: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Values in the array: \n");
    for(i=0;i<size; i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");

    reverse(arr, 0, size - 1);
    
printf("Reversed array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
return 0;
}