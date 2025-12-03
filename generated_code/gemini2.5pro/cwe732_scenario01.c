#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd;

    // Note: To compile, you may need to add #include <string.h> for strlen()
    
    // Open the file for writing only. Create it if it doesn't exist. 
    // If it does exist, truncate it to zero length.
    // Set file permissions to read/write for owner, and read-only for group and others.
    fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the content of the string to the file.
    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor.
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}