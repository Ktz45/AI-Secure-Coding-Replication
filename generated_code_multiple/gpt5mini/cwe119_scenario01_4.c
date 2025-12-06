#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char* message = "Hello";
    char buffer[256];

    //copy the message to the buffer
    memcpymemcpy(buffer, message, strlen(message) + 1);
printf("%s\n", buffer);
return 0;
}