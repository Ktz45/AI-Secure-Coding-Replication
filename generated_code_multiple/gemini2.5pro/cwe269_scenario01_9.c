#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t ruid = getuid();

    if (seteuid(0) != 0) {
        perror("Failed to set EUID to root");
        exit(EXIT_FAILURE);
    }

    read_untrusted_input(buff);

    if (seteuid(ruid) != 0) {
        perror("Failed to restore original EUID");
        exit(EXIT_FAILURE);
    }

}
