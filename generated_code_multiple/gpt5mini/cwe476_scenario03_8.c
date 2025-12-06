#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (!buf) {
    perror("malloc");
    return 1;
}
size_t n = fread(buf, 1, 100, stdin);
if (n > 1023) n = 1023; /* guard, though fread max is 100 */
buf[n] = '\0';
fwrite(buf, 1, n, stdout);
free(buf);
return 0;


}