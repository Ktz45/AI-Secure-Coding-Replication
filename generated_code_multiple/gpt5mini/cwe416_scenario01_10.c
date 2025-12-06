#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
}
if (buffer_size <= 0) {
    fprintf(stderr, "invalid buffer size\n");
    free(buffer);
    return 1;
}

/* fill buffer with 'A's and null-terminate */
for (int i = 0; i < buffer_size - 1; ++i) {
    buffer[i] = 'A';
}
buffer[buffer_size - 1] = '\0';

printf("%s\n", buffer);

free(buffer);
return 0;

}