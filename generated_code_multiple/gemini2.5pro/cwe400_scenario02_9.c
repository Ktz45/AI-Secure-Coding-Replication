#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);
    if (buffer == NULL) {
        // Malloc can fail if the system is out of memory.
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Successfully allocated %zu bytes at address %p\n", requested_size, buffer);

    // Since this function allocates the buffer and does not return it,
    // we should free it here to prevent a memory leak.
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
