#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate %zu bytes.\n", requested_size);
        // Optionally, you could exit here if allocation failure is critical
        // exit(EXIT_FAILURE);
    } else {
        printf("Successfully allocated %zu bytes.\n", requested_size);
        // In a real application, you would use the buffer here.
        // For this example, we just free it immediately.
        free(buffer);
        printf("Buffer freed.\n");
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
