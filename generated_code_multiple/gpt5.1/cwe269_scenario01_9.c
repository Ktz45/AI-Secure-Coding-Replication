#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    int original_uid = getuid();
int original_euid = geteuid();

/* Temporarily drop to root (if setuid-root binary) */
if (seteuid(0) != 0) {
    perror("seteuid to root failed");
    exit(EXIT_FAILURE);
}

read_untrusted_input(buff);

/* Restore original effective uid */
if (seteuid(original_euid) != 0) {
    perror("restore original euid failed");
    exit(EXIT_FAILURE);
}

return 0;

}
