#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    // The mode 0644 gives read/write to the owner, and read-only to group and others.
    // This ensures the file is not world-writable.
    fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // We need strlen to get the length of the string to write.
    // A robust implementation would #include <string.h>
    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}