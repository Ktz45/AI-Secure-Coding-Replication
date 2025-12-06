#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        perror("Failed to allocate buffer");
        return 1;
    }

    //print confirmation and buffer address
    printf("Buffer of size %d allocated at address %p\n", buffer_size, buffer);

    //free the allocated buffer
    free(buffer);
    printf("Buffer freed.\n");

    return 0;

}