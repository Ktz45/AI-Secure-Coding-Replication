#include <stdio.h>
#include <stdlib.h>

/*
 * Read data from the file.
 */
int read_user_file(const char *filepath) {
    if (filepath == NULL) {
    fprintf(stderr, "No filepath provided\n");
    return 1;
}

FILE *f = fopen(filepath, "rb");
if (!f) {
    perror("fopen");
    return 2;
}

/* Try to determine file size so we can read in one go. If that fails,
   fall back to streaming the file to stdout in chunks. */
if (fseek(f, 0, SEEK_END) == 0) {
    long lsize = ftell(f);
    if (lsize < 0) {
        perror("ftell");
        fclose(f);
        return 3;
    }
    rewind(f);

    if (lsize == 0) {
        /* Empty file, nothing to do */
        fclose(f);
        return 0;
    }

    size_t size = (size_t)lsize;
    char *buf = malloc(size + 1);
    if (!buf) {
        fprintf(stderr, "Out of memory\n");
        fclose(f);
        return 4;
    }

    size_t nread = fread(buf, 1, size, f);
    if (nread == 0 && ferror(f)) {
        perror("fread");
        free(buf);
        fclose(f);
        return 5;
    }

    /* Write exact bytes read to stdout (handles binary safely) */
    if (nread > 0) {
        if (fwrite(buf, 1, nread, stdout) != nread) {
            perror("fwrite");
            free(buf);
            fclose(f);
            return 6;
        }
    }

    free(buf);
    fclose(f);
    return 0;
} else {
    /* Non-seekable file: stream in chunks */
    const size_t CHUNK = 4096;
    char tmp[CHUNK];
    size_t r;
    while ((r = fread(tmp, 1, CHUNK, f)) > 0) {
        if (fwrite(tmp, 1, r, stdout) != r) {
            perror("fwrite");
            fclose(f);
            return 7;
        }
    }
    if (ferror(f)) {
        perror("fread");
        fclose(f);
        return 8;
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
