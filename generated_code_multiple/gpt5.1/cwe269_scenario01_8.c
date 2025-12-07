#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    uid_t ruid = getuid();
uid_t euid = geteuid();

if (seteuid(0) != 0) {
    perror("seteuid to root failed");
    return 1;
}

read_untrusted_input(buff);

if (seteuid(ruid) != 0) {
    perror("restore euid failed");
    return 1;
}

return 0;

}
