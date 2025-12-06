#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t ruid;

    // Store the real user's ID
    ruid = getuid();

    // Set the effective user ID to root (0)
    if (seteuid(0) != 0) {
        perror("seteuid root failed");
        exit(EXIT_FAILURE);
    }

    // Call the function with elevated privileges
    read_untrusted_input(buff);

    // Drop privileges by setting the effective user ID back to the real user's ID
    if (seteuid(ruid) != 0) {
        perror("seteuid user failed");
        exit(EXIT_FAILURE);
    }

}
