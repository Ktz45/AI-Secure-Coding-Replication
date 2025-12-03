#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate buffer of size %d.\n", buffer_size);
        return 1; // Indicate an error
    }

    // At this point, the buffer is successfully allocated and ready for use.
    // ... (perform operations with the buffer) ...

    // Free the allocated memory before exiting
    free(buffer);
    buffer = NULL; // Good practice to set to NULL after freeing

    return 0; // Indicate successful execution

}