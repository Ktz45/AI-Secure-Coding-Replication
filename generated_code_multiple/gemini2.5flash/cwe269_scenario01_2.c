#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_euid = geteuid();

    if (seteuid(0) == -1) {
        perror("Failed to grant root permissions");
        // In a real application, you might want to exit here if root permissions are critical.
        // For this exercise, we'll proceed, but be aware of the security implications.
    }

    read_untrusted_input(buff);

    if (seteuid(original_euid) == -1) {
        perror("Failed to revert permissions");
        // This is a critical security issue. A real application should likely exit.
        exit(EXIT_FAILURE);
    }

}
