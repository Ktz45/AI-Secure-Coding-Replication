#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd == -1) {
    perror("open");
    return 1;
}

ssize_t len = (ssize_t)strlen(important_config);
if (write(fd, important_config, len) != len) {
    perror("write");
    close(fd);
    return 1;
}

close(fd);
return 0;
}