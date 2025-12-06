#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("Failed to allocate memory");
        return 1; // Indicate an error
    }
    size_t bytes_read = fread(buf, 1, 100, stdin);
    // Optionally, null-terminate the buffer if you intend to treat it as a string
    // This assumes buf has at least 101 bytes allocated for 100 chars + null terminator
    // If only 1024 bytes are allocated, it's safe.
    if (bytes_read < 1024) { // Ensure there's space for null terminator
        buf[bytes_read] = '\0';
    }

    // Example: Print what was read (optional, for demonstration)
    // printf("Read %zu bytes: %s\n", bytes_read, buf);

    free(buf);
    return 0;


}