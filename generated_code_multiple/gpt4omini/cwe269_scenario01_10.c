#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    setuid(0); // Set user ID to root
    read_untrusted_input(buff); // Read untrusted input into the buffer
    setuid(getuid()); // Reset user ID to original

}
