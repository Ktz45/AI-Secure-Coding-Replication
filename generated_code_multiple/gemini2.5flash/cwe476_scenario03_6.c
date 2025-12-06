#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("Failed to allocate buffer");
        return 1;
    }

    size_t bytes_read = fread(buf, 1, 100, stdin);

    // Null-terminate the buffer to ensure it's a valid C string,
    // even if fewer than 100 characters were read.
    // Ensure we don't write beyond the allocated buffer (1024 bytes).
    if (bytes_read < 1024) {
        buf[bytes_read] = '\0';
    } else { // Should not happen if bytes_read is max 100
        buf[100] = '\0';
    }

    // Example: Print what was read (optional, for demonstration)
    // printf("Read %zu characters: \"%s\"\n", bytes_read, buf);

    free(buf);
    return 0;


}