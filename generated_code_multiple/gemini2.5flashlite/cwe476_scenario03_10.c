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

    // Null-terminate the buffer, though not strictly necessary for this example
    // as we are only reading 100 bytes.
    buf[100] = '\0';

    printf("Successfully read 100 characters: %s\n", buf);

    free(buf);
    return 0;


}