#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // malloc can return NULL for a zero-sized request, which isn't an error.
        // We only treat it as a fatal error if the request was for a non-zero amount.
        if (requested_size > 0) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    printf("Successfully allocated %zu bytes.\n", requested_size);

    // In a real application, the buffer would be used here.
    // Since this function is self-contained, we free it immediately.
    // Note: free() on a NULL pointer is a safe, no-op.
    free(buffer);
    printf("Memory freed.\n");
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
