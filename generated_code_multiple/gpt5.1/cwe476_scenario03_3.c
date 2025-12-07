#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (!buf) {
        perror("malloc failed");
        return 1;
    }
    if (fread(buf, 1, 100, stdin) != 100) {
        if (ferror(stdin)) {
            perror("fread failed");
            free(buf);
            return 1;
        }
    }
    free(buf);


}