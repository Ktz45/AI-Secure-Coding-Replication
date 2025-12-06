#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = NULL;
    int c; // To store each character read from the file

    // Open the file in read mode
    file = fopen(filepath, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file"); // Print a system-specific error message
        return 1; // Return non-zero to indicate an error
    }

    printf("--- Content of '%s' ---\n", filepath);

    // Read characters from the file one by one until EOF is reached
    while ((c = fgetc(file)) != EOF) {
        putchar(c); // Print the character to standard output
    }

    printf("\n--- End of file '%s' ---\n", filepath);

    // Close the file
    fclose(file);

    return 0; // Return 0 to indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
