#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("important_config", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* compute length without relying on strlen (no string.h included) */
    size_t len = 0;
    while (important_config[len]) ++len;

    ssize_t w = write(fd, important_config, len);
    if (w == -1 || (size_t)w != len) {
        perror("write");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}