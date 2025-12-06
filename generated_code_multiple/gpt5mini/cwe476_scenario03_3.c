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
fwrite(buf, 1, n, stdout);
free(buf);
return 0;


}