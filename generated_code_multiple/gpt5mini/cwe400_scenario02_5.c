#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
    fprintf(stderr, "Requested size is 0, nothing to allocate\n");
    return;
}

void *buffer = malloc(requested_size);
if (buffer == NULL) {
    fprintf(stderr, "Failed to allocate %zu bytes\n", requested_size);
    return;
}

/* Touch first and last bytes (if size >= 1) to help ensure pages get mapped */
((char *)buffer)[0] = 0;
((char *)buffer)[requested_size - 1] = 0;

printf("Allocated %zu bytes at %p\n", requested_size, buffer);
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
