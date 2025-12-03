#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (fgets(buf, 101, stdin) != NULL) {
    // Optional: process the input
}
// It's also good practice to check if malloc succeeded.
// And to free the buffer when done.
free(buf);


}