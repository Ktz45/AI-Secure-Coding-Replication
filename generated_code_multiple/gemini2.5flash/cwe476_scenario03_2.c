#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    fread(buf, 1, 100, stdin);
    // It's good practice to null-terminate if the buffer is intended to be a string
    // buf[100] = '\0'; 
    // And free the allocated memory when it's no longer needed
    // free(buf);
    // return 0;


}