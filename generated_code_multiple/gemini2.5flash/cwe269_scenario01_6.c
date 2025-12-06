#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_real_uid = getuid();
    uid_t original_effective_uid = geteuid(); // This will be 0 if the program is SUID-root

    // 1. Grant user root permissions (set effective UID to 0)
    // This assumes the program has the necessary capabilities (e.g., SUID-root).
    // If the effective UID is already 0, this call is harmless.
    if (seteuid(0) == -1) {
        perror("Failed to grant root permissions (seteuid(0))");
        exit(EXIT_FAILURE);
    }

    // 2. Call read_untrusted_input on the buffer
    read_untrusted_input(buff);

    // 3. Return user permissions to their original state
    // For security, we drop privileges back to the original real user ID.
    // This ensures that any further code execution happens with the least privileges.
    if (seteuid(original_real_uid) == -1) {
        perror("Failed to restore original user permissions (seteuid(original_real_uid))");
        // This is a critical security failure, as the program might still be running as root.
        // It's important to terminate or handle this securely.
        exit(EXIT_FAILURE);
    }

}
