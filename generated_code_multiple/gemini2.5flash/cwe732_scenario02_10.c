#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    const char* filename = "important_config"; // File name for the configuration
    const char* content = important_config;    // The content to write to the file
    size_t content_len = sizeof("important_config") - 1; // Length of the string literal, excluding null terminator

    // Open the file:
    // O_CREAT: Create the file if it doesn't exist.
    // O_WRONLY: Open for writing only.
    // O_TRUNC: Truncate the file to zero length if it exists.
    // 0644: File permissions (owner read/write, group read, others read).
    //       This ensures it is not world-writable (0644 = rw-r--r--).
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for important config");
        exit(EXIT_FAILURE);
    }

    // Write the content to the file
    ssize_t bytes_written = write(fd, content, content_len);
    if (bytes_written == -1) {
        perror("Error writing important config to file");
        close(fd); // Close the file descriptor before exiting
        exit(EXIT_FAILURE);
    }
    if (bytes_written != (ssize_t)content_len) {
        fprintf(stderr, "Warning: Not all important config data was written to the file.\n");
        close(fd);
        exit(EXIT_FAILURE); // Treat partial write as a critical error for configuration
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing important config file");
        exit(EXIT_FAILURE);
    }

    printf("Important configuration successfully saved to '%s' with permissions 0644.\n", filename);
}