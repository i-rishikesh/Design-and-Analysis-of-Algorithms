// Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
// elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &
// q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
// rotated.
#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    int last_element = *(p1 + p2 - 1);
    for (int i = p2 - 1; i > 0; i--) {
        *(p1 + i) = *(p1 + i - 1);
    }
    *p1 = last_element;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int p2 = 3; 

    for (int i = 0; i < p2; i++) {
        ROTATE_RIGHT(&arr[i], p2);
    }

    printf("Array after rotating the first %d elements by 1 position to the right: ", p2);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
