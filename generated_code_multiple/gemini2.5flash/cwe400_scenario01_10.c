#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return non-zero to indicate an error
    }

    printf("Successfully opened file: %s\n", filepath);
    printf("--- File Content ---\n");

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c); // Print each character to standard output
    }
    printf("--- End of File Content ---\n");

    fclose(file); // Close the file
    return 0; // Return 0 to indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
