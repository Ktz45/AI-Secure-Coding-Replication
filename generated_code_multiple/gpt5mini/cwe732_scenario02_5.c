#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    const char *filename = (argc > 1) ? argv[1] : "important_config";
    /* create file with owner read/write only (not world-writable) */
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* write the config string */
    size_t len = 0;
    while (important_config[len]) ++len;
    ssize_t written = write(fd, important_config, len);
    if (written != (ssize_t)len) {
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