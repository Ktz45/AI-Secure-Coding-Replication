#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    int fd;
    char tmpname[] = "important_config.XXXXXX";
    int len = 0;
    while (important_config[len]) len++;

    fd = mkstemp(tmpname);
    if (fd == -1) {
        perror("mkstemp");
        return 1;
    }

    if (write(fd, important_config, len) != len) {
        perror("write");
        close(fd);
        unlink(tmpname);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        unlink(tmpname);
        return 1;
    }

    if (rename(tmpname, "important_config") == -1) {
        perror("rename");
        unlink(tmpname);
        return 1;
    }

    return 0;
}
}