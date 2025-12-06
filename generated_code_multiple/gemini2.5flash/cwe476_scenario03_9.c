#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    fread(buf, 1, 100, stdin);
    // Optionally, null-terminate if the buffer is intended to be used as a string
    // buf[100] = '\0';
    // Don't forget to free the allocated memory later: free(buf);


}