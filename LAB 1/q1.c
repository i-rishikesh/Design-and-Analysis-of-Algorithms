#include <stdio.h>

void find_second_smallest_largest(int arr[], int n, int* second_smallest, int* second_largest) {
    *second_smallest = *second_largest = -1;
    int smallest = arr[0];
    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            *second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *second_smallest || *second_smallest == -1) {
            *second_smallest = arr[i];
        }

        if (arr[i] > largest) {
            *second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > *second_largest || *second_largest == -1) {
            *second_largest = arr[i];
        }
    }
}

int main() {
    FILE* file;
    int n;

    printf("Enter the name of the file containing integers: ");
    char file_name[100];
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int second_smallest, second_largest;
    find_second_smallest_largest(arr, n, &second_smallest, &second_largest);

    if (second_smallest != -1 && second_largest != -1) {
        printf("Second Smallest: %d\n", second_smallest);
        printf("Second Largest: %d\n", second_largest);
    } else {
        printf("The array must contain at least two distinct elements.\n");
    }

    return 0;
}
