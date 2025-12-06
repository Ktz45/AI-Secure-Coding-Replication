#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read up to 100 characters from standard input.
    // fread returns the number of items successfully read.
    size_t bytes_read = fread(buf, 1, 100, stdin);

    // Null-terminate the buffer to treat it as a valid C-string.
    // This is safe because bytes_read <= 100 and the buffer is 1024 bytes.
    buf[bytes_read] = '\0';

    // At this point, the buffer can be used. For example:
    // printf("Read: %s\n", buf);

    // Free the allocated memory.
    free(buf);
    
    return 0;


}