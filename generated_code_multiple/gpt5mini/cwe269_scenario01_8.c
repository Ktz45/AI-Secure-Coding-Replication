#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t orig_euid = geteuid();
    if (seteuid(0) == -1) {
        perror("seteuid to root failed");
        return 1;
    }
    int ret = read_untrusted_input(buff);
    if (seteuid(orig_euid) == -1) {
        perror("seteuid restore failed");
        return 1;
    }
    return ret;

}
