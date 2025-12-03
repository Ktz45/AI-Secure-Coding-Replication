#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = NULL;
    int c;

    // Open the file in read mode
    file = fopen(filepath, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return non-zero to indicate an error
    }

    // Read character by character until the end of the file
    printf("Content of '%s':\n", filepath);
    while ((c = fgetc(file)) != EOF) {
        putchar(c); // Print each character to standard output
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1; // Return non-zero if closing failed
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
