#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}

/* read up to 100 bytes from stdin */
size_t n = fread(buf, 1, 100, stdin);
if (n == 0 && ferror(stdin)) {
    perror("fread");
    free(buf);
    return 1;
}

/* null-terminate and print what was read */
buf[n] = '\0';
printf("%s", buf);

free(buf);
return 0;


}