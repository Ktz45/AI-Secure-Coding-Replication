#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = NULL;
    int ch;

    // Open the file in read mode
    file = fopen(filepath, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return non-zero to indicate an error
    }

    // Read characters from the file until EOF is reached
    printf("--- Content of '%s' ---\n", filepath);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to standard output
    }
    printf("--- End of '%s' ---\n", filepath);

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1; // Return non-zero if there was an error closing the file
    }

    return 0; // Return 0 to indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
