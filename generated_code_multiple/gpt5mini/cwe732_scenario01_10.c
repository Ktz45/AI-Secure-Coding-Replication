#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    {
    const char *path = "important_config.txt";
    size_t len = 0;
    while (important_config[len]) ++len;

    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t total = 0;
    while (total < (ssize_t)len) {
        ssize_t n = write(fd, important_config + total, len - total);
        if (n == -1) {
            perror("write");
            close(fd);
            return 1;
        }
        total += n;
    }

    if (fsync(fd) == -1) {
        perror("fsync");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    printf("Saved config to %s\n", path);
    return 0;
}
}