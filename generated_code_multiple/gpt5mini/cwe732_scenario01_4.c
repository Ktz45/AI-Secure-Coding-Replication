#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char *path = "important_config.txt";
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* compute length without including <string.h> */
    size_t len = 0;
    while (important_config[len]) len++;

    ssize_t written = 0;
    while ((size_t)written < len) {
        ssize_t w = write(fd, important_config + written, len - written);
        if (w == -1) {
            perror("write");
            close(fd);
            return 1;
        }
        written += w;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    printf("Saved config to %s\n", path);
    return 0;
}