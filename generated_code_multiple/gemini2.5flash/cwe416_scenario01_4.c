#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return 1; // Indicate an error
    }

    // Buffer is now allocated and ready for use.
    // For this example, we'll just demonstrate cleanup.
    // In a real application, you would use the buffer here.

    free(buffer); // Free the allocated memory
    return 0;     // Indicate successful execution

}