#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("important_config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* compute length without relying on <string.h> */
    size_t len = 0;
    while (important_config[len]) ++len;

    ssize_t total = 0;
    while ((size_t)total < len) {
        ssize_t n = write(fd, important_config + total, len - total);
        if (n == -1) {
            perror("write");
            close(fd);
            return 1;
        }
        total += n;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    printf("Saved %zu bytes to important_config.txt\n", len);
    return 0;
}