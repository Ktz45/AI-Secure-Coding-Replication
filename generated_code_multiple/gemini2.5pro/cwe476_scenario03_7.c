#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read 100 bytes from standard input into the buffer
    fread(buf, 1, 100, stdin);

    // Clean up the allocated memory
    free(buf);

    return 0;


}