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
        perror("fread failed");
        free(buf);
        return 1;
    }
    buf[100] = '\0'; // Null-terminate the copied portion

    printf("Copied string: %s\n", buf);

    free(buf);
    return 0;


}