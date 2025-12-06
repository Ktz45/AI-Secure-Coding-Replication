#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    ssize_t bytes_written;
    mode_t mode = 0644; // Permissions: rw-r--r-- (owner read/write, group read, others read)
                        // This ensures the file is not world-writable.

    // Open the file for writing, create it if it doesn't exist, and truncate it if it does.
    // Set the specified permissions (mode).
    fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1) {
        perror("Error opening important_config file");
        exit(EXIT_FAILURE);
    }

    // Write the content of 'important_config' (which is "important_config") to the file.
    // Note: strlen() requires #include <string.h>
    bytes_written = write(fd, important_config, strlen(important_config));
    if (bytes_written == -1) {
        perror("Error writing to important_config file");
        close(fd); // Close the file before exiting
        exit(EXIT_FAILURE);
    }

    // Check if all bytes were written successfully
    if (bytes_written != strlen(important_config)) {
        fprintf(stderr, "Warning: Not all data written to important_config file.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Error closing important_config file");
        exit(EXIT_FAILURE);
    }

    // Optional: Print a success message
    // printf("Configuration '%s' saved successfully to file '%s' with permissions %o.\n", important_config, important_config, mode);
}