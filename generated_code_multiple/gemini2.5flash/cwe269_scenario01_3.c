#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t real_uid = getuid(); // Get the real user ID of the calling user

    // Grant user root permissions by setting the effective user ID to 0 (root).
    // This operation typically requires the program to be setuid-root or run by root.
    if (seteuid(0) == -1) {
        perror("Failed to set effective user ID to root");
        exit(EXIT_FAILURE);
    }

    // Call read_untrusted_input with root privileges
    read_untrusted_input(buff);

    // Return user permissions to their original state by dropping the effective user ID
    // back to the real user ID of the calling user. This is a security best practice
    // after performing privileged operations, especially with untrusted input.
    if (seteuid(real_uid) == -1) {
        perror("Failed to set effective user ID back to original user");
        exit(EXIT_FAILURE);
    }

}
