#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
    printf("Requested size is zero, nothing to allocate\n");
    return;
}

void *buf = malloc(requested_size);
if (buf == NULL) {
    fprintf(stderr, "malloc failed for size %zu\n", requested_size);
    return;
}

printf("Allocated %zu bytes at %p\n", requested_size, buf);

/* Touch one byte per page to force allocation (avoid lazy commit) */
volatile unsigned char *p = buf;
size_t page = 4096;
for (size_t i = 0; i < requested_size; i += page) {
    p[i] = 0;
}
if (requested_size > 0) {
    p[requested_size - 1] = 0;
}

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
