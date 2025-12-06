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
    if (!fp) {
        perror("fopen");
        return 1;
    }

    unsigned char buf[4096];
    size_t nread;
    while ((nread = fread(buf, 1, sizeof buf, fp)) > 0) {
        size_t nwritten = fwrite(buf, 1, nread, stdout);
        if (nwritten != nread) {
            perror("fwrite");
            fclose(fp);
            return 1;
        }
    }

    if (ferror(fp)) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    if (fclose(fp) == EOF) {
        perror("fclose");
        return 1;
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
