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

    //initialize buffer with zeros
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0;
    }

    //print buffer size and address
    printf("Buffer allocated with size: %d bytes\n", buffer_size);
    printf("Buffer address: %p\n", (void *)buffer);

    //free buffer
    free(buffer);

    return 0;

}