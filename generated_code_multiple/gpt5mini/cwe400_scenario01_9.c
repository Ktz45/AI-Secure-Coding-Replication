#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    {
    if (filepath == NULL) {
        fprintf(stderr, "No filepath provided\n");
        return 1;
    }

    FILE *fp = fopen(filepath, "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, fp)) > 0) {
        size_t written = fwrite(buf, 1, n, stdout);
        if (written != n) {
            perror("fwrite");
            fclose(fp);
            return 3;
        }
    }

    if (ferror(fp)) {
        perror("fread");
        fclose(fp);
        return 2;
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
