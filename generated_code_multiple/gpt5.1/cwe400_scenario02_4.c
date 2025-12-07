#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);
if (buffer == NULL) {
    fprintf(stderr, "Memory allocation failed for size %zu bytes.\n", requested_size);
    return;
}

printf("Successfully allocated %zu bytes.\n", requested_size);

/* Use the buffer here as needed */

/* Free the allocated memory */
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
