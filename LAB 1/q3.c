//WAP to read 'n' integer from a disc file that must contain some duplicate values and store them into 
// an array .Perform the following operations on the array .
//a)Find out the total number if duplicate elements.
// b)Find out the most repeating element in the array.
#include <stdio.h>

void find_duplicates(int arr[], int n, int* total_duplicates, int* most_repeating_element) {
    *total_duplicates = 0;
    *most_repeating_element = arr[0];
    int max_repeats = 1;

    for (int i = 0; i < n; i++) {
        int repeats = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                repeats++;
            }
        }
        if (repeats > max_repeats) {
            max_repeats = repeats;
            *most_repeating_element = arr[i];
        }
        if (repeats > 1) {
            (*total_duplicates) += (repeats - 1);
        }
    }
}

int main() {
    FILE* file;
    int n;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    printf("Enter the name of the file containing integers: ");
    char file_name[100];
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int total_duplicates, most_repeating_element;
    find_duplicates(arr, n, &total_duplicates, &most_repeating_element);

    printf("Total number of duplicate elements: %d\n", total_duplicates);
    printf("Most repeating element: %d\n", most_repeating_element);

    return 0;
}
