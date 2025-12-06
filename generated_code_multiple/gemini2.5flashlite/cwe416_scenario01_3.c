#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    //use buffer (example: fill with 'A')
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 'A';
    }

    //print a message indicating success and buffer size
    printf("Buffer of size %d allocated and filled.\n", buffer_size);

    //free the allocated memory
    free(buffer);

    return 0;
}

}