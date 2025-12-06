#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    if (setuid(0) != 0) {
        perror("setuid");
        return 1;
    }

    read_untrusted_input(buff);

    if (setuid(getuid()) != 0) {
        perror("setuid");
        return 1;
    }

    return 0;
}

}
