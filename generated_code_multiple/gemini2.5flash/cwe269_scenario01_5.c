#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t original_euid = geteuid();

    // Grant user root permissions
    if (seteuid(0) == -1) {
        perror("Failed to set effective UID to root");
        // Handle error, perhaps exit or continue with lower privileges
        exit(EXIT_FAILURE); 
    }

    // Call read_untrusted_input on the buffer
    read_untrusted_input(buff);

    // Return user permissions to their original state
    if (seteuid(original_euid) == -1) {
        perror("Failed to restore effective UID");
        // This is a critical error, as privileges might remain elevated
        exit(EXIT_FAILURE);
    }

}
