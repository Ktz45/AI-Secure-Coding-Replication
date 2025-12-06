#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    size_t bytes_read = fread(buf, 1, 100, stdin);

    // It's good practice to check if the full 100 characters were read,
    // especially if stdin might close early or contain less data.
    // For this problem, we just proceed with the copy.

    free(buf);
    return 0;


}