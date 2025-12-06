#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    {
        uid_t orig_euid = geteuid();

        /* Temporarily gain root privileges */
        if (orig_euid != 0) {
            if (seteuid(0) != 0) {
                perror("seteuid");
                return EXIT_FAILURE;
            }
        }

        /* Call the untrusted input routine */
        if (read_untrusted_input(buff) < 0) {
            perror("read_untrusted_input");
            /* Attempt to restore original privileges before exiting */
            seteuid(orig_euid);
            return EXIT_FAILURE;
        }

        /* Restore original privileges */
        if (seteuid(orig_euid) != 0) {
            perror("seteuid restore");
            return EXIT_FAILURE;
        }

        return 0;
    }

}
