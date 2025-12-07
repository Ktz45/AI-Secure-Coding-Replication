#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (ferror(fp)) {
        perror("fgetc");
        fclose(fp);
        return 1;
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
