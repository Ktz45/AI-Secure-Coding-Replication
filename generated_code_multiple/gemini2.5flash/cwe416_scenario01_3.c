#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // At this point, 'buffer' is successfully allocated and can be used.
    // For example, you could initialize it or read/write to it.
    // memset(buffer, 0, buffer_size); // Example: initialize to zeros
    // printf("Buffer of size %d bytes allocated successfully.\n", buffer_size);

    // Free the allocated memory before exiting
    free(buffer);

    return EXIT_SUCCESS;

}