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

    // use the buffer (for example, read from stdin)
    size_t bytes_read = fread(buffer, 1, buffer_size, stdin);
    if (bytes_read > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    free(buffer);
    return 0;

}