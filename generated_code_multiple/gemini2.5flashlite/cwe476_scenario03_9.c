#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("malloc");
        return 1;
    }
    if (fread(buf, 1, 100, stdin) != 100) {
        fprintf(stderr, "Error reading 100 bytes from stdin\n");
        free(buf);
        return 1;
    }
    buf[100] = '\0'; // Null-terminate for safe string operations
    printf("Read: %s\n", buf);
    free(buf);
    return 0;


}