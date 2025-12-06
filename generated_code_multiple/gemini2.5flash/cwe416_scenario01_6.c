#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate buffer of size %d bytes.\n", buffer_size);
        return 1; // Indicate an error
    }

    // Buffer is successfully allocated here.
    // In a real application, you would use the buffer here (e.g., read data into it, process it).
    printf("Successfully allocated buffer of size %d bytes.\n", buffer_size);

    // Free the allocated memory before the program exits
    free(buffer);
    // It's good practice to set the pointer to NULL after freeing
    // to prevent accidental use of a dangling pointer.
    buffer = NULL;

    return 0; // Indicate successful execution

}