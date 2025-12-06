#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (!buf) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}

size_t n = fread(buf, 1, 100, stdin);
if (n == 0 && ferror(stdin)) {
    perror("fread");
    free(buf);
    return 1;
}

/* null-terminate so buf can be used as a string */
buf[n] = '\0';

/* use the buffer (for example, print what was read) */
printf("%s", buf);

free(buf);
return 0;


}