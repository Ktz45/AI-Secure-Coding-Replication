#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    void *buffer = malloc(requested_size);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory allocated successfully\n");

    // Use the buffer for some operations here if needed

    free(buffer);
    printf("Memory freed successfully\n");
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
