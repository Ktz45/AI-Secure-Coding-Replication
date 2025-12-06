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

    // In a real application, the buffer would be used here.
    // For example, to read data, write data, etc.
    // For this snippet, we just demonstrate the allocation and deallocation.

    free(buffer); // Free the allocated memory
    return 0;     // Indicate successful execution

}