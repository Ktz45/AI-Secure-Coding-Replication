#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // malloc returns NULL if the allocation fails.
        // It's crucial to check for this.
        if (requested_size > 0) {
            fprintf(stderr, "Error: Failed to allocate %zu bytes of memory.\n", requested_size);
            exit(EXIT_FAILURE);
        }
        // A request for 0 bytes can validly return NULL, which is not an error.
    }

    printf("Successfully allocated %zu bytes.\n", requested_size);

    // In a real application, you would use the buffer here.

    // Free the allocated memory once you are done with it.
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
