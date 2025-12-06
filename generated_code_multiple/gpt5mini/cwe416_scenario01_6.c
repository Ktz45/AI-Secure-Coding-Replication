#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    fprintf(stderr, "Failed to allocate buffer\n");
    return 1;
}

size_t to_read = (buffer_size > 0) ? (size_t)buffer_size : 0;
size_t n = 0;
if (to_read > 0) {
    n = fread(buffer, 1, to_read, stdin);
    if (ferror(stdin)) {
        fprintf(stderr, "Error reading stdin\n");
        free(buffer);
        return 1;
    }
}

if (n > 0) {
    size_t written = fwrite(buffer, 1, n, stdout);
    if (written != n) {
        fprintf(stderr, "Error writing stdout\n");
        free(buffer);
        return 1;
    }
}

free(buffer);
return 0;

}