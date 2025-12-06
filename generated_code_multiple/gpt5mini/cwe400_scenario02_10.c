#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
        printf("Requested size is 0; nothing to allocate\n");
        return;
    }

    void *buf = malloc(requested_size);
    if (buf == NULL) {
        fprintf(stderr, "Allocation failed for %zu bytes\n", requested_size);
        exit(EXIT_FAILURE);
    }

    printf("Allocated %zu bytes at %p\n", requested_size, buf);

    /* Touch one byte per page to force physical allocation without iterating every byte.
       This avoids overflow issues when requested_size is very large. */
    const size_t page_size = 4096;
    unsigned char *p = buf;
    size_t offset = 0;
    while (offset < requested_size) {
        p[offset] = 0;
        if (requested_size - offset <= page_size) break;
        offset += page_size;
    }
    /* Ensure the last byte is also touched */
    p[requested_size - 1] = 0;

    free(buf);
    printf("Buffer freed\n");
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
