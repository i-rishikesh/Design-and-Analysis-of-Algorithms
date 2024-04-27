#include <stdio.h>

// Function to perform Insertion Sort
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        
        arr[j + 1] = key;
    }
    return comparisons;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Choose the input scenario:\n");
    printf("1. Best Case (Ascending order)\n");
    printf("2. Worst Case (Descending order)\n");
    printf("3. Average Case (Random order)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    char inputFileName[20];
    switch (choice) {
        case 1:
            strcpy(inputFileName, "inAsce.dat");
            break;
        case 2:
            strcpy(inputFileName, "inDesc.dat");
            break;
        case 3:
            strcpy(inputFileName, "inRand.dat");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        printf("Could not open the input file.\n");
        return 1;
    }
    
    int n;
    fscanf(inputFile, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);
    
    int comparisons = insertionSort(arr, n);
    
    FILE *outputFile = fopen("outSorted.dat", "w");
    if (!outputFile) {
        printf("Could not open the output file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);
    
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Number of comparisons made: %d\n", comparisons);
    
    if (choice == 1) {
        printf("Input scenario is a best case.\n");
    } else if (choice == 2) {
        printf("Input scenario is a worst case.\n");
    } else {
        printf("Input scenario is an average case.\n");
    }
    
    return 0;
}
