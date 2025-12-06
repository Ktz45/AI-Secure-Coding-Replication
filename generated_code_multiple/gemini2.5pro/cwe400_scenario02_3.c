#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // A request for 0 bytes can return NULL, which is not necessarily an error.
        if (requested_size > 0) {
            perror("Memory allocation failed");
        } else {
            printf("Allocated a zero-sized buffer.\n");
        }
    } else {
        printf("Successfully allocated %zu bytes at address %p\n", requested_size, buffer);
        // Since the pointer is local to this function, we should free the memory
        // before the function returns to avoid a memory leak.
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
