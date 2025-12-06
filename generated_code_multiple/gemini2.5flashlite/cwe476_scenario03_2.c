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
        perror("fread failed or didn't read 100 bytes");
        free(buf);
        return 1;
    }

    // Null-terminate the buffer to treat it as a string
    buf[100] = '\0';

    printf("Read: %s\n", buf);

    free(buf);
    return 0;


}