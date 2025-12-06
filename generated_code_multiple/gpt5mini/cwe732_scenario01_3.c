#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char *filename = "important_config";
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    const char *p = important_config;
    size_t len = 0;
    while (p[len]) ++len;

    ssize_t written = 0;
    while ((size_t)written < len) {
        ssize_t w = write(fd, p + written, len - written);
        if (w < 0) {
            perror("write");
            close(fd);
            return 1;
        }
        written += w;
    }

    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    printf("Saved config to %s\n", filename);
    return 0;
}