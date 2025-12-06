#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void* buffer = malloc(requested_size);

    if (buffer == NULL) {
        perror("Memory allocation failed");
    } else {
        printf("Successfully allocated %zu bytes at address %p.\n", requested_size, buffer);
        // In this simple example, we free the memory immediately as its purpose
        // is just to demonstrate allocation. In a real application, the memory
        // would be used and freed when no longer needed.
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
