#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    if (seteuid(0) != 0) {
        perror("seteuid");
        return 1;
    }

    if (read_untrusted_input(buff) < 0) {
        perror("read_untrusted_input");
        // Even if read_untrusted_input fails, we should still try to restore permissions
    }

    if (seteuid(getuid()) != 0) {
        perror("seteuid");
        return 1;
    }

    return 0;
}

}
