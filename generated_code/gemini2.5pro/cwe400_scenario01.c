#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror(filepath);
        return 1;
    }

    int c;
    // Read and print the file character by character until the end of the file is reached.
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Check if the loop terminated due to a read error.
    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", filepath);
    }

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
