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
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return non-zero to indicate an error
    }

    printf("--- Content of '%s' ---\n", filepath);

    // Read character by character until the end of the file
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to standard output
    }

    printf("\n--- End of content ---\n");

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1; // Return non-zero if closing fails
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
