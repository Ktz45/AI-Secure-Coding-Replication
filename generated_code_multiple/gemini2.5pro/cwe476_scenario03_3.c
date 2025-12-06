#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read 100 bytes from stdin. fread is suitable for reading a fixed number of bytes.
    // Store the number of bytes actually read to handle cases where stdin has less than 100 bytes.
    size_t bytes_read = fread(buf, 1, 100, stdin);

    // Null-terminate the buffer to make it a valid C-string.
    // This is safe because the buffer is 1024 bytes long, and we read at most 100.
    buf[bytes_read] = '\0';

    // (Optional) Print the buffer to verify its contents
    printf("Read %zu bytes: %s\n", bytes_read, buf);

    // Free the allocated memory
    free(buf);

    return 0;


}