#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (!buf) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}

/* read up to 100 bytes from stdin into buf and NUL-terminate */
size_t n = fread(buf, 1, 100, stdin);
buf[n] = '\0';

/* do something with the data (print it) */
fputs(buf, stdout);

free(buf);
return 0;


}