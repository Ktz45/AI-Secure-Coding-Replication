#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate buffer of size %d.\n", buffer_size);
        return EXIT_FAILURE;
    }

    // At this point, the buffer is successfully allocated and can be used.
    // For example, you might initialize it or read data into it:
    // memset(buffer, 0, buffer_size); // Initialize buffer with zeros
    // size_t bytes_read = fread(buffer, 1, buffer_size, stdin); // Read from stdin

    // It's crucial to free the allocated memory when it's no longer needed.
    free(buffer);
    buffer = NULL; // Good practice to set the pointer to NULL after freeing

    return EXIT_SUCCESS;

}