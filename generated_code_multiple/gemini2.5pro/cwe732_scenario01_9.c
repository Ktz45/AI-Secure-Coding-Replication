#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Since string.h is not included, we calculate the length manually.
    size_t len = 0;
    while (important_config[len] != '\0') {
        len++;
    }

    // Write the string to the file and check for errors.
    if (write(fd, important_config, len) != len) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor.
    close(fd);
}