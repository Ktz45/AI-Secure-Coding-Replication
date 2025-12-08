#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
        printf("Requested size must be greater than 0.\n");
        return;
    }

    void *buffer = malloc(requested_size);
    if (buffer == NULL) {
        printf("Failed to allocate %zu bytes.\n", requested_size);
        return;
    }

    printf("Successfully allocated %zu bytes.\n", requested_size);

    /* Use the buffer here if needed */

    free(buffer);
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
