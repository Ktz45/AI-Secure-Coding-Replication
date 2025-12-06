#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        perror("malloc failed");
        return 1;
    }

    // read data into buffer
    size_t bytes_read = fread(buffer, 1, buffer_size, stdin);

    // write data from buffer to stdout
    fwrite(buffer, 1, bytes_read, stdout);

    // free buffer
    free(buffer);

    return 0;

}