#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int size = 500;  // Maximum size
    int arr[size];

    while (1) {
        printf("1. Ascending Order\n2. Descending Order\n3. Random Data\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char *input_filename, *output_filename;

        switch (choice) {
            case 1:
                input_filename = "inAsce.dat";
                output_filename = "outQuickAsce.dat";
                break;
            case 2:
                input_filename = "inDesc.dat";
                output_filename = "outQuickDesc.dat";
                break;
            case 3:
                input_filename = "inRand.dat";
                output_filename = "outQuickRand.dat";
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                continue;
        }

        read_data(input_filename, arr, size);

        comparisons = 0;  

        clock_t start_time = clock();
        quick_sort(arr, 0, size - 1);
        clock_t end_time = clock();

        write_data(output_filename, arr, size);

        printf("Sorted data: ");
        print_array(arr, size);

        printf("Number of comparisons: %d\n", comparisons);

        double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Execution time: %lf seconds\n", execution_time);

        if (comparisons == (size - 1)) {
            printf("Partitioning scenario: Best-case\n\n");
        } else if (comparisons == ((size - 1) * (size - 2)) / 2) {
            printf("Partitioning scenario: Worst-case\n\n");
        } else {
            printf("Partitioning scenario: Neither best-case nor worst-case\n\n");
        }
    }

    return 0;
}
