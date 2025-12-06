#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (argc < 2) {
    fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
    return 1;
}
if (buffer_size <= 0) {
    fprintf(stderr, "buffer_size must be positive\n");
    free(buffer);
    return 1;
}
if (buffer == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}

/* read up to buffer_size-1 bytes from stdin, null-terminate, print */
size_t n = fread(buffer, 1, (size_t)buffer_size - 1, stdin);
buffer[n] = '\0';
fputs(buffer, stdout);

free(buffer);
return 0;

}