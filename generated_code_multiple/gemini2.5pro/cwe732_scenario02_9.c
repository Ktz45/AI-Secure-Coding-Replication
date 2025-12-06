#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    // The third argument to open() sets the file permissions.
    // 0644 provides read/write for the owner, and read-only for group and others.
    // This ensures the file is not world-writable.
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Using sizeof("...")-1 gets the length of the string literal at compile time
    // without needing to include <string.h> for strlen().
    ssize_t bytes_written = write(fd, important_config, sizeof("important_config") - 1);
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    printf("Configuration saved to file '%s'.\n", important_config);

    return 0;
}