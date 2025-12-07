#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
        return 1;
    }

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // use the buffer (for example, fill with 'A's and null-terminate if possible)
    if (buffer_size > 0) {
        for (int i = 0; i < buffer_size - 1; i++) {
            buffer[i] = 'A';
        }
        buffer[buffer_size - 1] = '\0';
        printf("%s\n", buffer);
    }

    free(buffer);
    return 0;

}