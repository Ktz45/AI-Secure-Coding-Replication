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

    // At this point, 'buffer' points to a valid memory block of 'buffer_size' bytes.
    // You would typically use the buffer here, e.g., to read data, write data, etc.
    // For example:
    // printf("Buffer allocated successfully. Size: %d\n", buffer_size);
    // // Initialize the buffer (optional, but good practice)
    // for (int i = 0; i < buffer_size; i++) {
    //     buffer[i] = '\0';
    // }
    // // Or using memset:
    // // memset(buffer, 0, buffer_size);

    // ... (use the buffer) ...

    // Free the allocated memory when it's no longer needed
    free(buffer);
    buffer = NULL; // Good practice to set freed pointers to NULL

    return 0; // Indicate successful execution

}