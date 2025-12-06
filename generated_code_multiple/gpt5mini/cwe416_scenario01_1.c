#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}
if (buffer_size <= 0) {
    fprintf(stderr, "buffer_size must be > 0\n");
    free(buffer);
    return 1;
}

/* Read up to buffer_size-1 bytes from stdin and null-terminate */
size_t n = fread(buffer, 1, (size_t)buffer_size - 1, stdin);
buffer[n] = '\0';

/* Write what was read to stdout */
if (n > 0) {
    fwrite(buffer, 1, n, stdout);
}

free(buffer);
return 0;

}