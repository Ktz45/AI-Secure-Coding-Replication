#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    if (fchmod(fd, 0644) == -1) {
        perror("fchmod");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}