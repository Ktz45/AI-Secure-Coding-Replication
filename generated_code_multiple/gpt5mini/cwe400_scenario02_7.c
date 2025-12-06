#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
    printf("Requested size is 0, nothing to allocate.\n");
    return;
}

void *buf = malloc(requested_size);
if (buf == NULL) {
    fprintf(stderr, "Allocation failed for %zu bytes\n", requested_size);
    return;
}

/* Touch first and last byte to ensure the memory is usable (and not optimized away) */
unsigned char *p = buf;
p[0] = 0xAA;
p[requested_size - 1] = 0x55;

printf("Allocated %zu bytes at %p. first=0x%02x last=0x%02x\n",
       requested_size, buf, p[0], p[requested_size - 1]);

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
