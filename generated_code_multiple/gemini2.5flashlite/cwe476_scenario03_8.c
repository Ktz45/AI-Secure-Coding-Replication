#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("malloc failed");
        return 1;
    }

    if (fread(buf, 1, 100, stdin) != 100) {
        fprintf(stderr, "Error reading 100 bytes from stdin\n");
        free(buf);
        return 1;
    }

    // Now buf contains 100 characters from stdin.
    // You can do something with buf here, for example, print it:
    printf("Read from stdin: %s\n", buf);

    free(buf); // Free the allocated memory
    return 0;


}