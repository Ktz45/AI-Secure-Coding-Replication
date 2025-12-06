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

    int c; // Use int to hold the return value of fgetc(), which includes EOF
    while ((c = fgetc(fp)) != EOF) {
        putchar(c); // Print the character to standard output
    }

    if (ferror(fp)) {
        perror("Error reading file");
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
