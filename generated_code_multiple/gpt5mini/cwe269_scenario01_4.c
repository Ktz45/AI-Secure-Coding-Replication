#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t saved_euid = geteuid();
    if (seteuid(0) != 0) {
        perror("seteuid(0) failed");
        return 1;
    }

    if (read_untrusted_input(buff) < 0) {
        perror("read_untrusted_input failed");
        /* try to drop privileges before exiting */
        seteuid(saved_euid);
        return 1;
    }

    if (seteuid(saved_euid) != 0) {
        perror("seteuid(restore) failed");
        return 1;
    }

    return 0;

}
