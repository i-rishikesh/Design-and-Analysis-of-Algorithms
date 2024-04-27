//Given an array arr[] of size N,find the prefix sum of the array.A prefix sum array is another array prefixSum[] 
// of the same size such that the value of prefixSum[i] is arr[0]+arr[1]+arr[2]+...+arr[i].
#include <stdio.h>

void calculate_prefix_sum(int arr[], int n, int prefixSum[]) {
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum[n];
    calculate_prefix_sum(arr, n, prefixSum);

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}
