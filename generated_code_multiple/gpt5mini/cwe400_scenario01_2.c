#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    {
    if (filepath == NULL) {
        fprintf(stderr, "read_user_file: filepath is NULL\n");
        return 1;
    }

    FILE *fp = fopen(filepath, "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (putchar(c) == EOF) {
            perror("putchar");
            fclose(fp);
            return 2;
        }
    }

    if (ferror(fp)) {
        perror("fgetc");
        fclose(fp);
        return 3;
    }

    if (fclose(fp) == EOF) {
        perror("fclose");
        return 4;
    }

    return 0;
}
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
