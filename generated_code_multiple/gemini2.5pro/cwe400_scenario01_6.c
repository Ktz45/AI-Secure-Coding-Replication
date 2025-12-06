#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file;
    int c;
    int status = 0;

    // Open the file in read mode.
    file = fopen(filepath, "r");
    if (file == NULL) {
        // If the file cannot be opened, print an error message to stderr
        // and return a non-zero status code to indicate failure.
        perror(filepath);
        return 1;
    }

    // Read the file one character at a time until the end of the file (EOF) is reached.
    while ((c = fgetc(file)) != EOF) {
        // Print the character to standard output.
        putchar(c);
    }

    // After the loop, check if it terminated due to a read error.
    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", filepath);
        status = 1; // Set status to indicate failure.
    }

    // Close the file to release system resources.
    fclose(file);

    // Return 0 for success, or 1 if a read error occurred.
    return status;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
