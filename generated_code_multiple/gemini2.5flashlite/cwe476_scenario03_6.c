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
        fprintf(stderr, "Failed to read 100 characters from stdin\n");
        free(buf);
        return 1;
    }

    // You can now use the 'buf' which contains 100 characters from stdin.
    // For example, to print them:
    // printf("Read: %.*s\n", 100, buf);

    free(buf);
    return 0;
}


}