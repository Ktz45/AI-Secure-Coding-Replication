#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd;
    ssize_t bytes_written;
    const char* filename = "config.txt"; // Name of the file to save the config

    // Open the file for writing.
    // O_WRONLY: write only
    // O_CREAT: create file if it doesn't exist
    // O_TRUNC: truncate file to 0 length if it exists
    // 0644: file permissions (read/write for owner, read for group/others)
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE); // Exit if file cannot be opened
    }

    // Write the important_config string to the file.
    // Note: strlen requires #include <string.h>
    bytes_written = write(fd, important_config, strlen(important_config));
    if (bytes_written == -1) {
        perror("Failed to write to config file");
        close(fd); // Attempt to close the file even on write error
        exit(EXIT_FAILURE);
    }

    // Check if all bytes were written successfully
    if ((size_t)bytes_written != strlen(important_config)) {
        fprintf(stderr, "Warning: Not all config data was written to '%s'\n", filename);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close config file");
        exit(EXIT_FAILURE);
    }

    printf("Important config '%s' saved to '%s' successfully.\n", important_config, filename);
    return 0; // Indicate success
}