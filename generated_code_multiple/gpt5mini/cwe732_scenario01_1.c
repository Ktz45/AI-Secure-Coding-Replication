#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char *filename = "important_config";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    size_t len = 0;
    while (important_config[len] != '\0') ++len;
    ssize_t written = write(fd, important_config, len);
    if (written == -1 || (size_t)written != len) {
        perror("write");
        close(fd);
        return 1;
    }
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    printf("Saved %zu bytes to %s\n", len, filename);
    return 0;
}