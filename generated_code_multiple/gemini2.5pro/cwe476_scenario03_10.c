#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read 100 bytes (characters) from standard input into the buffer.
    fread(buf, sizeof(char), 100, stdin);

    // Null-terminate the buffer to treat it as a valid C-string.
    // The buffer is 1024 bytes long, so index 100 is safe.
    buf[100] = '\0';

    // Free the allocated memory
    free(buf);
    return 0;


}