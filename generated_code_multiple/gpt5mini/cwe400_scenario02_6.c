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
    fprintf(stderr, "Allocation failed for %zu bytes\n", requested_size);
    exit(EXIT_FAILURE);
}

printf("Allocated %zu bytes at %p\n", requested_size, buf);

/* Touch memory in page-sized steps so the OS commits pages (avoid touching every byte). */
volatile unsigned char *p = (volatile unsigned char *)buf;
const size_t step = 4096;
for (size_t i = 0; i < requested_size; i += step) {
    p[i] = 0;
}
/* Ensure the last byte is touched too (if requested_size is not 0). */
p[requested_size - 1] = 0;

printf("Memory touched to ensure allocation is backed by pages\n");

free(buf);
printf("Freed memory\n");
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
