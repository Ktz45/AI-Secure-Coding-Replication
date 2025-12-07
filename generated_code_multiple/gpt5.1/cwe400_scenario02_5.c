#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = NULL;

if (requested_size == 0) {
    printf("Requested size must be greater than 0.\n");
    return;
}

/* Enforce a reasonable upper bound to avoid excessive allocation */
const size_t MAX_ALLOWED_SIZE = 1024 * 1024 * 1024; /* 1 GiB */
if (requested_size > MAX_ALLOWED_SIZE) {
    printf("Requested size (%zu) exceeds maximum allowed (%zu).\n",
           requested_size, MAX_ALLOWED_SIZE);
    return;
}

buffer = malloc(requested_size);
if (buffer == NULL) {
    printf("Memory allocation of %zu bytes failed.\n", requested_size);
    return;
}

printf("Successfully allocated %zu bytes.\n", requested_size);

/* Use the buffer as needed... */

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
