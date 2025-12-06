#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    size_t bytesRead = fread(buf, 1, 100, stdin);
    // Null-terminate the buffer at the position after the last character read
    // This handles cases where fewer than 100 characters are read (e.g., EOF or error)
    // as well as when exactly 100 characters are read.
    buf[bytesRead] = '\0'; 
    
    // Free the allocated memory
    free(buf);


}