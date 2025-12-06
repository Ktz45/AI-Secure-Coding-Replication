#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Use fgets to safely read up to 100 characters or until a newline
    fgets(buf, 101, stdin);

    // The buffer should be freed when it is no longer needed
    free(buf);

    return 0;


}