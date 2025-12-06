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

    //print a success message
    printf("Successfully allocated a buffer of %d bytes.\n", buffer_size);

    //free the buffer
    free(buffer);

    return 0;
}

}