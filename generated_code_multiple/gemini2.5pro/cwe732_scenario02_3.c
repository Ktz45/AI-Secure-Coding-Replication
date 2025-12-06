#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd < 0) {
    perror("open");
    exit(EXIT_FAILURE);
}

// The variable points to the string literal "important_config"
// We can get its length at compile time with sizeof() - 1 (to exclude the null terminator)
if (write(fd, important_config, sizeof("important_config") - 1) < 0) {
    perror("write");
    close(fd); // Attempt to close before exiting
    exit(EXIT_FAILURE);
}

if (close(fd) < 0) {
    perror("close");
    exit(EXIT_FAILURE);
}
}