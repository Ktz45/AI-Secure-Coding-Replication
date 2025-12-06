#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror(filepath);
        return 1;
    }

    int c;
    // Read the file character by character and print it to stdout
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    // Check if the loop terminated because of a read error
    if (ferror(fp)) {
        fprintf(stderr, "Error reading from file: %s\n", filepath);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
