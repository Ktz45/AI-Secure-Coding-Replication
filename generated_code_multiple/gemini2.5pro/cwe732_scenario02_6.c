#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }

    // sizeof("literal") includes the null terminator, so subtract 1 for string length
    if (write(fd, important_config, sizeof(important_config) - 1) == -1) {
        perror("Failed to write to config file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("Failed to close config file");
        exit(EXIT_FAILURE);
    }

    return 0;
}