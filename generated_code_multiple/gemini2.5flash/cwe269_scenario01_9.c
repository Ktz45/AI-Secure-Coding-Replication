#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_euid;

    // Save the original effective UID
    original_euid = geteuid();

    // Grant root permissions (set effective UID to 0)
    if (seteuid(0) == -1) {
        perror("Failed to set effective UID to root");
        exit(EXIT_FAILURE);
    }

    // Call read_untrusted_input on the buffer
    read_untrusted_input(buff);

    // Return user permissions to their original state (restore effective UID)
    if (seteuid(original_euid) == -1) {
        perror("Failed to restore effective UID");
        exit(EXIT_FAILURE);
    }

}
