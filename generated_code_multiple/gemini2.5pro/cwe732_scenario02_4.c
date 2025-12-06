#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    // Create/open the file for writing, truncate if it exists.
    // Set permissions to 0644 (owner can read/write, group/others can only read).
    // This satisfies the "not world-writable" requirement.
    fd = open("important_config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the configuration string to the file.
    // dprintf is a convenient POSIX function to print to a file descriptor.
    if (dprintf(fd, "%s\n", important_config) < 0) {
        perror("dprintf");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor.
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}