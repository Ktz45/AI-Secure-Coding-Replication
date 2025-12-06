#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char buf[4096];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            perror("fputs");
            fclose(fp);
            return 1;
        }
    }

    if (ferror(fp)) {
        perror("fgets");
        fclose(fp);
        return 1;
    }

    fclose(fp);
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
