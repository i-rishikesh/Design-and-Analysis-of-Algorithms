#include <stdio.h>

int binarySearchLeftmost(int arr[], int n, int target, int *comparisons) {
    int left = 0;
    int right = n - 1;
    int result = -1;  // Initialize result to -1
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Increment comparisons count
        (*comparisons)++;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Move left to find the leftmost occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    int comparisons = 0;  // Initialize comparisons count
    
    int position = binarySearchLeftmost(arr, n, target, &comparisons);
    
    if (position != -1) {
        printf("Element found at position %d.\n", position);
    } else {
        printf("Element not found in the array.\n");
    }
    
    printf("Number of comparisons made: %d\n", comparisons);
    
    return 0;
}
