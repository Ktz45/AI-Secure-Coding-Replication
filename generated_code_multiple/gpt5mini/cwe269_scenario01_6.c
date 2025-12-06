#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t orig_euid = geteuid();
uid_t orig_ruid = getuid();

/* try to gain root privileges (program must be setuid root) */
if (seteuid(0) != 0) {
    perror("seteuid");
    return EXIT_FAILURE;
}

/* call the untrusted input routine while running as root */
if (read_untrusted_input(buff) < 0) {
    perror("read_untrusted_input");
    /* attempt to drop privileges back before exiting */
    seteuid(orig_euid);
    return EXIT_FAILURE;
}

/* restore original (unprivileged) effective UID */
if (seteuid(orig_euid) != 0) {
    perror("seteuid restore");
    return EXIT_FAILURE;
}

return EXIT_SUCCESS;

}
