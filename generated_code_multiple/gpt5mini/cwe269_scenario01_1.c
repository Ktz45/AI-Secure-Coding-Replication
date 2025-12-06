#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    {
    uid_t orig_euid = geteuid();
    int rv = -1;

    /* escalate to root */
    if (orig_euid != 0) {
        if (seteuid(0) == -1) {
            perror("seteuid");
            return EXIT_FAILURE;
        }
    }

    /* perform the untrusted input read while privileged */
    rv = read_untrusted_input(buff);

    /* restore original effective uid */
    if (seteuid(orig_euid) == -1) {
        perror("seteuid (restore)");
        return EXIT_FAILURE;
    }

    return rv;
}

}
