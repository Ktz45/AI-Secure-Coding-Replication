#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);
    if (buffer == NULL) {
        fprintf(stderr, "Allocation of %zu bytes failed\n", requested_size);
        return;
    }

    printf("Successfully allocated %zu bytes\n", requested_size);

    /* Example use: initialize to zero */
    memset(buffer, 0, requested_size);

    /* Free the allocated buffer */
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
