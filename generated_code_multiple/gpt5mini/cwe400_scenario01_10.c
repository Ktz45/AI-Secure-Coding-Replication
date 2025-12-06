#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *f = fopen(filepath, "rb");
    if (!f) {
        perror("fopen");
        return 2;
    }

    unsigned char buf[8192];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, f)) > 0) {
        if (fwrite(buf, 1, n, stdout) != n) {
            perror("fwrite");
            fclose(f);
            return 4;
        }
    }

    if (ferror(f)) {
        perror("fread");
        fclose(f);
        return 3;
    }

    fclose(f);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    return read_user_file(argv[1]);
}
