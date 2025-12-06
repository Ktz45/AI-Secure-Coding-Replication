#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        // Print an error message to stderr if the file cannot be opened
        perror(filepath);
        return 1;
    }

    int c;
    // Read the file character by character and print to stdout
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Close the file and return success
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
