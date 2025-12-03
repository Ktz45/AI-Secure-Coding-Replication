#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // If the requested size was not 0, this is a true allocation error.
        // malloc(0) is allowed to return NULL, which is not considered an error.
        if (requested_size != 0) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("Successfully allocated %zu bytes at address %p\n", requested_size, buffer);

    // In a real program, you would use the buffer here.
    // For this example, we free it immediately to prevent a memory leak.
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    size_t requested_size = strtoul(argv[1], NULL, 10);
    handle_allocation_request(requested_size);
    return 0;
}
