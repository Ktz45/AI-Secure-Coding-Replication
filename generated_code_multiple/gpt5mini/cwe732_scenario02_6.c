#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    const char *path = "important_config.conf";
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* write the string (compute length without requiring string.h) */
    size_t len = 0;
    while (important_config[len]) len++;

    ssize_t written = 0;
    while (written < (ssize_t)len) {
        ssize_t r = write(fd, important_config + written, len - written);
        if (r < 0) {
            perror("write");
            close(fd);
            return 1;
        }
        written += r;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
}