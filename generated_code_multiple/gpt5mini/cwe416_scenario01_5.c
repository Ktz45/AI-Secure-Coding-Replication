#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //get buffer size from argv
    int buffer_size = atoi(argv[1]);
    //allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    if (buffer == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
}

if (buffer_size <= 0) {
    fprintf(stderr, "Invalid buffer size: %d\n", buffer_size);
    free(buffer);
    return 1;
}

/* Fill buffer with 'A's and null-terminate for safe printing */
for (int i = 0; i < buffer_size - 1; ++i) {
    buffer[i] = 'A';
}
buffer[buffer_size - 1] = '\0';

puts(buffer);

free(buffer);
return 0;

}