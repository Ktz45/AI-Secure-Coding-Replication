#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, 0600); // 0600: owner read/write, no access for group or others
    if (fd == -1) {
        perror("Failed to open important_config file");
        exit(EXIT_FAILURE);
    }

    // The content to be saved is the string literal "important_config" itself.
    // The variable 'important_config' holds this string.
    // Note: strlen requires <string.h>, which is commonly included for C programs.
    size_t content_len = strlen(important_config);
    ssize_t bytes_written = write(fd, important_config, content_len);

    if (bytes_written == -1) {
        perror("Failed to write to important_config file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // Check if all bytes were written
    if ((size_t)bytes_written != content_len) {
        fprintf(stderr, "Warning: Not all data was written to important_config file.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("Failed to close important_config file");
        exit(EXIT_FAILURE);
    }
}