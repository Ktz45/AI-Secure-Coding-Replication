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

    // At this point, 'buffer' is successfully allocated and ready for use.
    // In a real application, you would perform operations with the buffer here.
    // For example:
    // printf("Buffer of size %d allocated successfully.\n", buffer_size);
    // fgets(buffer, buffer_size, stdin);
    // printf("You entered: %s\n", buffer);

    // Free the allocated memory before exiting.
    free(buffer);
    buffer = NULL; // Good practice to set to NULL after freeing

    return 0; // Indicate successful execution

}