#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed for size %zu\n", requested_size);
        // In a real application, you might want to exit or handle this error more gracefully.
        // For this example, we'll just print an error and return.
        return;
    }
    printf("Successfully allocated %zu bytes at %p\n", requested_size, buffer);
    // In a real application, you would use the buffer here.
    // For this example, we'll just free it immediately.
    free(buffer);
    printf("Freed buffer at %p\n", buffer);
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
