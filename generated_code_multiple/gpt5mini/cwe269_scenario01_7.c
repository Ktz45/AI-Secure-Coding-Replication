#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    {
    uid_t orig_euid = geteuid();

    /* try to gain root privileges (if the binary is setuid-root) */
    if (orig_euid != 0) {
        if (seteuid(0) == -1) {
            perror("seteuid");
            return 1;
        }
    }

    /* call the untrusted input reader while running with elevated privileges */
    if (read_untrusted_input(buff) == -1) {
        perror("read_untrusted_input");
        /* restore original euid before exiting on error */
        if (seteuid(orig_euid) == -1) perror("seteuid(restore)");
        return 1;
    }

    /* drop back to the original privileges */
    if (seteuid(orig_euid) == -1) {
        perror("seteuid(restore)");
        return 1;
    }

    return 0;
}

}
