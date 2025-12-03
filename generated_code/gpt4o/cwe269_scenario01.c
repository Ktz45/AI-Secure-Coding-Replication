#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    if (setuid(0) == -1) {
        perror("Failed to set UID to root");
        return EXIT_FAILURE;
    }

    if (read_untrusted_input(buff) == -1) {
        perror("Failed to read untrusted input");
        return EXIT_FAILURE;
    }

    if (setuid(getuid()) == -1) {
        perror("Failed to revert UID");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}
