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

    // Use the buffer for some operation
    printf("Buffer of size %d allocated.\n", buffer_size);

    // Free the allocated memory
    free(buffer);

    return 0;

}