#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    // Read up to 100 characters from stdin
    if (fgets(buf, 101, stdin) != NULL) {
        // Optional: remove trailing newline character if it exists
        // size_t len = strlen(buf);
        // if (len > 0 && buf[len-1] == '\n') {
        //     buf[len-1] = '\0';
        // }
    }
    // It's also good practice to free the memory when done
    free(buf);
    return 0;


}