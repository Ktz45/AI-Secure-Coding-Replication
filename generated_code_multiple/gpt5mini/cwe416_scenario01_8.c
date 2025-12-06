#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
}
if (buffer_size <= 0) {
    fprintf(stderr, "Invalid buffer size\n");
    free(buffer);
    return 1;
}

/* read up to buffer_size bytes from stdin and write them to stdout */
size_t to_read = (size_t)buffer_size;
size_t nread = fread(buffer, 1, to_read, stdin);
if (nread > 0) {
    fwrite(buffer, 1, nread, stdout);
}

free(buffer);
return 0;

}