#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_euid = geteuid(); // Save the original effective user ID

    // Grant user root permissions (set effective user ID to 0)
    if (seteuid(0) == -1) {
        perror("Failed to set EUID to root");
        exit(EXIT_FAILURE);
    }

    // Call read_untrusted_input on the buffer
    read_untrusted_input(buff);

    // Return user permissions to their original state (restore original effective user ID)
    if (seteuid(original_euid) == -1) {
        perror("Failed to restore original EUID");
        exit(EXIT_FAILURE);
    }

}
