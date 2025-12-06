#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    if (setuid(0) != 0) {
        perror("setuid(0)");
        return 1;
    }

    if (read_untrusted_input(buff) < 0) {
        perror("read_untrusted_input");
        return 1;
    }

    if (setuid(getuid()) != 0) {
        perror("setuid(getuid())");
        return 1;
    }

    printf("Input: %s\n", buff);
    return 0;
}

}
