#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    // A size of 0 can be passed if the user enters "0" or invalid text.
    // We'll treat this as a case where no allocation is needed.
    if (requested_size == 0) {
        printf("Allocation size must be greater than zero.\n");
        return;
    }

    // Attempt to allocate the memory.
    void *buffer = malloc(requested_size);

    // Check if malloc failed (e.g., out of memory).
    if (buffer == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Successfully allocated %zu bytes.\n", requested_size);

    // In a real program, the buffer would be used here.
    // Since this function is self-contained, we free the memory before returning.
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
