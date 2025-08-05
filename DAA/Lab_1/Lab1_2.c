#include <stdio.h>

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[N];

    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    printf("Prefix Sum Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
    return 0;
}
