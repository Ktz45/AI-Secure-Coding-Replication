#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    size_t len = 0;
    while (important_config[len]) len++;

    int fd = open("important_config", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ssize_t n = write(fd, important_config, len);
    if (n < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    if ((size_t)n != len) {
        fprintf(stderr, "partial write\n");
        close(fd);
        return 1;
    }

    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}