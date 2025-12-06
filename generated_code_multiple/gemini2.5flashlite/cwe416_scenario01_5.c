#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    //check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    //print buffer size and address
    printf("Buffer allocated with size: %d at address: %p\n", buffer_size, buffer);

    //free buffer
    free(buffer);

    return 0;

}