#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, comparisons);
        merge_sort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

void read_data(char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_data(char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int size = 500;  // Maximum size
    int arr[size];
    int comparisons = 0;

    while (1) {
        printf("1. Ascending Order\n2. Descending Order\n3. Random Data\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char *input_filename, *output_filename;

        switch (choice) {
            case 1:
                input_filename = "inAsce.dat";
                output_filename = "outMergeAsce.dat";
                break;
            case 2:
                input_filename = "inDesc.dat";
                output_filename = "outMergeDesc.dat";
                break;
            case 3:
                input_filename = "inRand.dat";
                output_filename = "outMergeRand.dat";
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                continue;
        }

        read_data(input_filename, arr, size);

        clock_t start_time = clock();
        merge_sort(arr, 0, size - 1, &comparisons);
        clock_t end_time = clock();

        write_data(output_filename, arr, size);

        printf("Sorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of comparisons: %d\n", comparisons);
        double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Execution time: %lf seconds\n\n", execution_time);
    }

    return 0;
}
