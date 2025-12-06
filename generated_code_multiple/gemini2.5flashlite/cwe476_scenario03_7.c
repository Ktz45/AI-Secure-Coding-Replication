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

    // Optionally, null-terminate the buffer if you intend to treat it as a string
    // buf[100] = '\0';

    // Now 'buf' contains 100 characters read from stdin.
    // You can further process 'buf' here.

    // For demonstration, let's print the first 10 characters
    // printf("First 10 characters: ");
    // for (int i = 0; i < 10; i++) {
    //     putchar(buf[i]);
    // }
    // putchar('\n');

    free(buf);
    return 0;


}