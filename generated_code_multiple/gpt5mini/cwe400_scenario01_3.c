#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    {
    FILE *f = fopen(filepath, "rb");
    if (!f) {
        perror(filepath);
        return 1;
    }

    /* Try to determine file size and read in one shot */
    if (fseek(f, 0, SEEK_END) == 0) {
        long sz = ftell(f);
        if (sz < 0) {
            perror("ftell");
            fclose(f);
            return 2;
        }
        rewind(f);

        char *buf = malloc((size_t)sz + 1);
        if (!buf) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(f);
            return 3;
        }

        size_t got = fread(buf, 1, (size_t)sz, f);
        if (got != (size_t)sz && ferror(f)) {
            perror("fread");
            free(buf);
            fclose(f);
            return 4;
        }
        /* Print exact bytes read (handles binary/text) */
        if (got > 0) fwrite(buf, 1, got, stdout);
        free(buf);
    } else {
        /* Fallback for non-seekable streams: read in chunks and grow buffer as needed */
        size_t cap = 4096;
        size_t len = 0;
        char *buf = malloc(cap);
        if (!buf) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(f);
            return 5;
        }

        while (1) {
            if (len == cap) {
                size_t newcap = cap * 2;
                char *tmp = realloc(buf, newcap);
                if (!tmp) {
                    fprintf(stderr, "Memory allocation failed\n");
                    free(buf);
                    fclose(f);
                    return 6;
                }
                buf = tmp;
                cap = newcap;
            }
            size_t n = fread(buf + len, 1, cap - len, f);
            if (n == 0) break;
            len += n;
        }

        if (ferror(f)) {
            perror("fread");
            free(buf);
            fclose(f);
            return 7;
        }

        if (len > 0) fwrite(buf, 1, len, stdout);
        free(buf);
    }

    fclose(f);
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
