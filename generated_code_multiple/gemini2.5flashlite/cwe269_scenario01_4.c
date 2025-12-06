#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    setuid(0); // Grant root privileges
    read_untrusted_input(buff); // Read input from an untrusted source
    setuid(getuid()); // Return user permissions to their original state
    return 0;
}

}
