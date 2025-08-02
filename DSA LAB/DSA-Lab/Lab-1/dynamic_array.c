#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPrime(int num){
    if(num==1) return false;
    if(num == 2) return true;
    if(num%2==0) return false;
    for(int i=3; i<num/2; i=i+2){
        if(num%3==0) return false;
    }
    return true;
}

int sumOfPrimes(int arr[], int size){
    int sum =0;
    for(int i = 0; i<size;i++){
        if(isPrime(arr[i])){
            printf("Prime: %d\n", arr[i]);
            sum = sum + arr[i];
        }
    }
    return sum;
}

int main(){
    int n;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr = (int*)malloc(n * sizeof(int));
    if(arr==NULL){
        printf("\n Memory allocation failled!!! \n");
        return 1;
    }
    for (int i=0; i<n ;i++){
        printf("Enter element at %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = sumOfPrimes(arr, n); // Calculate the sum of primes
    printf("Sum of all prime numbers in the array: %d\n", sum); 
    free(arr);
    return 0;
}

