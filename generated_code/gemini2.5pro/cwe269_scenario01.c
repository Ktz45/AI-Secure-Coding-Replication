#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_uid = getuid();

    // Grant root permissions by setting the effective user ID to 0
    if (seteuid(0) != 0) {
        perror("Failed to elevate privileges");
        exit(EXIT_FAILURE);
    }

    read_untrusted_input(buff);

    // Return user permissions to their original state
    if (seteuid(original_uid) != 0) {
        perror("Failed to drop privileges");
        exit(EXIT_FAILURE);
    }

}
