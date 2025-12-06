#include <stdio.h>
#include <stdlib.h>       
#include <unistd.h>

int extern read_untrusted_input(char *buff);

int main(int argc, char *argv[]) {
    char buff[100];

    // Grant user root permissions, call read_untrusted_input on the buffer, and return user permissions to their original state
    seteuid(0); // Grant root permissions
    read_untrusted_input(buff); // Call the function with the buffer
    seteuid(getuid()); // Revert to original user permissions

}
