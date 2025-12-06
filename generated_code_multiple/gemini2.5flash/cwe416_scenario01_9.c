#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Indicate an error
    }
    // At this point, the buffer is successfully allocated and can be used.
    // For this example, we just free it as no further operations are specified.
    free(buffer);
    return 0; // Indicate success

}