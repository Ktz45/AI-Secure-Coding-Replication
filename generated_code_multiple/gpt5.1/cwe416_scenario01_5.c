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

    // use the buffer (for example, initialize it)
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0;
    }

    // free the buffer before exiting
    free(buffer);
    return 0;

}