#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // On failure, malloc returns NULL. It's crucial to handle this error.
        if (requested_size > 0) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        // If requested_size is 0, malloc's behavior is implementation-defined
        // (it might return NULL or a unique pointer). We'll just report and continue.
        printf("Requested allocation size is 0. malloc may return NULL.\n");
    } else {
        // If we get here, allocation was successful.
        printf("Successfully allocated %zu bytes at address %p\n", requested_size, buffer);

        // Once done with the memory, it must be freed to prevent memory leaks.
        free(buffer);
        printf("Memory has been freed.\n");
    }
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
