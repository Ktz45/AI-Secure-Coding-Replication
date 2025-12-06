#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    perror("malloc");
    return 1;
}
if (buffer_size <= 0) {
    fprintf(stderr, "Invalid buffer size\n");
    free(buffer);
    return 1;
}

size_t nread;
while ((nread = fread(buffer, 1, (size_t)buffer_size, stdin)) > 0) {
    size_t nwritten = 0;
    while (nwritten < nread) {
        size_t w = fwrite(buffer + nwritten, 1, nread - nwritten, stdout);
        if (w == 0) {
            if (ferror(stdout)) {
                perror("fwrite");
                free(buffer);
                return 1;
            }
            break;
        }
        nwritten += w;
    }
    if (ferror(stdin)) {
        perror("fread");
        free(buffer);
        return 1;
    }
}

free(buffer);
return 0;

}