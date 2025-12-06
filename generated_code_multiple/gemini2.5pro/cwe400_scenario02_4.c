#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);

    if (buffer == NULL) {
        // malloc can return NULL if size is 0 or if allocation fails.
        // We only report an error if the requested size was greater than 0.
        if (requested_size > 0) {
            perror("Memory allocation failed");
        } else {
            printf("Requested allocation size is 0.\n");
        }
        return;
    }

    printf("Successfully allocated %zu bytes at address %p\n", requested_size, buffer);

    // In a real application, the allocated memory would be used here.
    // Since this function's scope is just to demonstrate allocation,
    // we free the memory immediately to prevent a leak.
    free(buffer);
    printf("Memory has been freed.\n");
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
