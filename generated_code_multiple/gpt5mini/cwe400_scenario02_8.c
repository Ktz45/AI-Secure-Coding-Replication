#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate a buffer of the requested size.
 */
void handle_allocation_request(size_t requested_size) {
    if (requested_size == 0) {
    printf("Requested size is 0; nothing to allocate.\n");
    return;
}

unsigned char *buf = malloc(requested_size);
if (buf == NULL) {
    fprintf(stderr, "Allocation failed for %zu bytes\n", requested_size);
    return;
}

/* Touch the buffer to ensure pages are actually committed */
for (size_t i = 0; i < requested_size; ++i) {
    buf[i] = 0;
}

printf("Successfully allocated and zeroed %zu bytes\n", requested_size);
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
