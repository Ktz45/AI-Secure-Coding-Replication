#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_euid = geteuid(); // Save the current effective user ID

    // Attempt to grant root permissions (set effective UID to 0)
    if (seteuid(0) == -1) {
        perror("seteuid(0) failed to grant root permissions");
        exit(EXIT_FAILURE); // Exit if unable to gain root privileges
    }

    // Call read_untrusted_input with root permissions
    read_untrusted_input(buff);

    // Return user permissions to their original state
    if (seteuid(original_euid) == -1) {
        perror("seteuid(original_euid) failed to return permissions");
        exit(EXIT_FAILURE); // Exit if unable to drop privileges back
    }

}
