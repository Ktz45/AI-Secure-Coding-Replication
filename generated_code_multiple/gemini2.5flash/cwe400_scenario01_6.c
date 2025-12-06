#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Indicate failure
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to stdout
    }

    if (ferror(file)) {
        perror("Error reading from file");
        fclose(file);
        return 1; // Indicate failure
    }

    fclose(file);
    return 0; // Indicate success
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
