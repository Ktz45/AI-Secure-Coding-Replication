#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read up to 100 characters from stdin into buf.
    // We use 101 as the size to leave space for the null terminator.
    fgets(buf, 101, stdin);

    // The buffer should be freed when it is no longer needed.
    free(buf);

    return 0;


}