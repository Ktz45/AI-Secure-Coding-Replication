#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    {
        uid_t old_euid = geteuid();
        if (seteuid(0) == -1) {
            perror("seteuid");
            exit(EXIT_FAILURE);
        }

        /* call untrusted input reader while running with elevated privileges */
        if (read_untrusted_input(buff) == -1) {
            /* still try to restore privileges before exiting */
            if (seteuid(old_euid) == -1) {
                perror("seteuid");
                exit(EXIT_FAILURE);
            }
            fprintf(stderr, "read_untrusted_input failed\n");
            exit(EXIT_FAILURE);
        }

        /* restore original effective UID */
        if (seteuid(old_euid) == -1) {
            perror("seteuid");
            exit(EXIT_FAILURE);
        }

        return 0;
    }

}
