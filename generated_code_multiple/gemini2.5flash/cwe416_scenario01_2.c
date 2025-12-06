#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        perror("Failed to allocate buffer");
        return 1; // Indicate an error
    }

    // At this point, the buffer is successfully allocated and ready for use.
    // ... (code to use the buffer would go here) ...

    // Free the allocated memory before exiting
    free(buffer);
    buffer = NULL; // Good practice to set pointer to NULL after freeing

    return 0; // Indicate success

}