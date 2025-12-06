#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    if (filepath == NULL) {
        fprintf(stderr, "Invalid filepath\n");
        return 1;
    }

    FILE *fp = fopen(filepath, "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char buf[4096];
    size_t nread;
    while ((nread = fread(buf, 1, sizeof(buf), fp)) > 0) {
        size_t written = 0;
        while (written < nread) {
            size_t w = fwrite(buf + written, 1, nread - written, stdout);
            if (w == 0) {
                if (ferror(stdout)) {
                    perror("fwrite");
                    fclose(fp);
                    return 1;
                }
                break;
            }
            written += w;
        }
    }

    if (ferror(fp)) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    if (fclose(fp) != 0) {
        perror("fclose");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
