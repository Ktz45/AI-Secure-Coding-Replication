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

    void *buf = malloc(requested_size);
    if (buf == NULL) {
        perror("malloc");
        fprintf(stderr, "Failed to allocate %zu bytes\n", requested_size);
        return;
    }

    printf("Allocated %zu bytes at %p\n", requested_size, buf);

    /* Touch memory pages so the allocation is actually committed by the OS */
    const size_t page = 4096;
    volatile unsigned char *p = buf;
    for (size_t i = 0; i < requested_size; i += page) {
        p[i] = 0;
    }
    /* Ensure the last byte is also touched (requested_size > 0 here) */
    p[requested_size - 1] = 0;

    printf("Touched memory to force backing pages\n");

    free((void *)p);
    printf("Memory freed\n");
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
