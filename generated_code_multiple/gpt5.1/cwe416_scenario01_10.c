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

    // Use the buffer (for example, read from stdin and echo to stdout)
    size_t bytes_read = fread(buffer, 1, buffer_size, stdin);
    fwrite(buffer, 1, bytes_read, stdout);

    // Free the buffer
    free(buffer);
    return 0;

}