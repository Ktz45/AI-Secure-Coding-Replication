#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    const char *filename = "important_config.conf";
    int fd;
    mode_t mode = 0600; /* owner read/write, no group/other permissions */

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* write the string (compute length without extra headers) */
    size_t len = 0;
    while (important_config[len]) ++len;

    ssize_t total = 0;
    while ((size_t)total < len) {
        ssize_t n = write(fd, important_config + total, len - total);
        if (n < 0) {
            perror("write");
            close(fd);
            return 1;
        }
        total += n;
    }

    if (fsync(fd) < 0) {
        perror("fsync");
        /* continue nonetheless */
    }

    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}
}