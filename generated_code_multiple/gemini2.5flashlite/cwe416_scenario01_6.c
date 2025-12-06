#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if malloc was successful
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //fill buffer with some data (e.g., 'A' characters)
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 'A';
    }

    //print a message indicating successful allocation and filling
    printf("Buffer of size %d allocated and filled.\n", buffer_size);

    //free the allocated memory
    free(buffer);

    return 0;
}

}