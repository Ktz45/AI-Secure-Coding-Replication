#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("Failed to allocate buffer");
        return 1;
    }
    size_t bytesRead = fread(buf, 1, 100, stdin);
    // Ensure the buffer is null-terminated if fewer than 100 bytes were read,
    // or if it's intended to be treated as a string.
    // The buffer size is 1024, so buf[100] is safe.
    if (bytesRead < 1024) { // Check to prevent writing beyond the buffer if somehow bytesRead was larger (though fread limits it)
        buf[bytesRead] = '\0';
    } else { // If exactly 1024 bytes were read (not the case here, we read max 100)
        buf[1023] = '\0'; // Null-terminate at the end of the buffer
    }
    
    // Optionally, print what was read for demonstration
    // printf("Read %zu bytes: \"%s\"\n", bytesRead, buf);

    free(buf);
    return 0;


}