#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
        printf("Requested size is 0, nothing to allocate\n");
        return;
    }

    char *buf = malloc(requested_size);
    if (buf == NULL) {
        fprintf(stderr, "Failed to allocate %zu bytes\n", requested_size);
        return;
    }

    /* Touch memory pages to ensure allocation is realized without
       writing every byte (use ~4KB stride). */
    size_t stride = 4096;
    for (size_t i = 0; i < requested_size; i += stride) {
        buf[i] = 0;
    }
    /* Ensure the last byte is touched */
    buf[requested_size - 1] = 0;

    printf("Successfully allocated %zu bytes at %p\n", requested_size, (void *)buf);
    free(buf);
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
