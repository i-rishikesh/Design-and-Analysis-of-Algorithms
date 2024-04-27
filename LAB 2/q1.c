// Write a program in C to convert the first ‘n’ decimal numbers of a disc
// file to binary using recursion. Store the binary value in a separate disc file.
#include <stdio.h>

void decimal_to_binary(int decimal_num, FILE* binary_file) {
    if (decimal_num > 0) {
        decimal_to_binary(decimal_num / 2, binary_file);
        fprintf(binary_file, "%d", decimal_num % 2);
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    int n, decimal_num;

    printf("Enter how many decimal numbers you want to read from the file: ");
    scanf("%d", &n);

    printf("Enter the name of the file containing decimal numbers: ");
    char input_file_name[100];
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    printf("Enter the name of the file to store binary numbers: ");
    char output_file_name[100];
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        fclose(input_file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &decimal_num);
        decimal_to_binary(decimal_num, output_file);
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    printf("Conversion completed and binary values stored in the output file.\n");

    return 0;
}
