#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Use fgets to safely read up to 100 characters from stdin.
    // The size is 101 to leave space for the null terminator.
    fgets(buf, 101, stdin);

    // The memory should be freed when it's no longer needed.
    free(buf);

    return 0;


}