#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    FILE *f = fopen(filepath, "rb");
if (!f) {
    perror(filepath);
    return 1;
}

const size_t CHUNK = 4096;
char *buf = NULL;
size_t cap = 0;
size_t len = 0;

for (;;) {
    if (cap - len < CHUNK) {
        size_t newcap = cap ? cap * 2 : CHUNK;
        while (newcap - len < CHUNK) newcap *= 2;
        char *tmp = realloc(buf, newcap);
        if (!tmp) {
            perror("realloc");
            free(buf);
            fclose(f);
            return 1;
        }
        buf = tmp;
        cap = newcap;
    }

    size_t n = fread(buf + len, 1, CHUNK, f);
    if (n == 0) break;
    len += n;
}

if (ferror(f)) {
    perror("fread");
    free(buf);
    fclose(f);
    return 1;
}

/* Write to stdout (preserve binary-safe write) */
if (len > 0) {
    size_t written = fwrite(buf, 1, len, stdout);
    if (written != len) {
        perror("fwrite");
        free(buf);
        fclose(f);
        return 1;
    }
}

free(buf);
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
