#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    if (fgets(buf, 100, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        free(buf);
        return 1;
    }

    printf("Input: %s\n", buf);
    free(buf);
    return 0;


}