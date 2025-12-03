#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    // The mode 0644 gives read/write to the owner, and read-only to group and world.
    // This satisfies the "not world-writable" requirement.
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // dprintf writes to a file descriptor and is declared in stdio.h
    if (dprintf(fd, "%s\n", important_config) < 0) {
        perror("dprintf");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}