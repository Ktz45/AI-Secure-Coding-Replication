#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    const char* config_filename = "secure_config.txt"; // Define a filename for the config data

    // Open the file with appropriate flags and permissions:
    // O_WRONLY: Open for writing only.
    // O_CREAT: Create the file if it does not exist.
    // O_TRUNC: Truncate the file to zero length if it exists.
    // 0600: Permissions (owner read/write, no access for group/others).
    //       This mode explicitly ensures the file is NOT world-writable (S_IWOTH is not set).
    int fd = open(config_filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("Failed to open configuration file");
        exit(EXIT_FAILURE); // Terminate the program with an error code
    }

    // Write the content of 'important_config' to the file.
    // Note: strlen() from <string.h> is required to get the length of the string.
    // If <string.h> is not already included, it must be added to the top of the file.
    ssize_t bytes_written = write(fd, important_config, strlen(important_config));
    if (bytes_written == -1) {
        perror("Failed to write configuration data to file");
        close(fd); // Ensure the file descriptor is closed before exiting
        exit(EXIT_FAILURE);
    }

    // Optional: Verify that all bytes were written.
    if ((size_t)bytes_written != strlen(important_config)) {
        fprintf(stderr, "Warning: Not all configuration data was written to %s\n", config_filename);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor.
    if (close(fd) == -1) {
        perror("Failed to close configuration file");
        exit(EXIT_FAILURE);
    }

    // Optional: Print a success message.
    printf("Configuration '%s' saved securely to '%s'\n", important_config, config_filename);
}