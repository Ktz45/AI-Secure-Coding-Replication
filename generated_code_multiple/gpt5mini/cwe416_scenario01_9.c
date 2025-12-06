#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (argc < 2) {
    fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
    free(buffer);
    return 1;
}

if (buffer == NULL) {
    perror("malloc");
    return 1;
}

if (buffer_size <= 0) {
    fprintf(stderr, "buffer_size must be > 0\n");
    free(buffer);
    return 1;
}

/* Copy stdin to stdout using the allocated buffer in chunks */
size_t bs = (size_t)buffer_size;
size_t n;
while ((n = fread(buffer, 1, bs, stdin)) > 0) {
    size_t written = 0;
    while (written < n) {
        size_t w = fwrite(buffer + written, 1, n - written, stdout);
        if (w == 0) {
            perror("fwrite");
            free(buffer);
            return 1;
        }
        written += w;
    }
}

if (ferror(stdin)) {
    perror("fread");
    free(buffer);
    return 1;
}

free(buffer);
return 0;

}