// Write a program in C to find GCD of two numbers using recursion.
// Read all pairs of numbers from a file and store the result in a seperate file.
// Note# Source file name and destination file name taken from command line arguments. The
// source file must contain at least 20 pairs of numbers.
#include <stdio.h>

int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file_name> <destination_file_name>\n", argv[0]);
        return 1;
    }

    char *source_file_name = argv[1];
    char *destination_file_name = argv[2];

    FILE *source_file = fopen(source_file_name, "r");
    if (source_file == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    FILE *destination_file = fopen(destination_file_name, "w");
    if (destination_file == NULL) {
        printf("Error opening the destination file.\n");
        fclose(source_file);
        return 1;
    }

    int a, b;
    while (fscanf(source_file, "%d %d", &a, &b) == 2) {
        int gcd = gcd_recursive(a, b);
        fprintf(destination_file, "%d\n", gcd);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("GCD calculation completed and results stored in the destination file.\n");

    return 0;
}
