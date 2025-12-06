#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    ssize_t bytes_written;
    size_t config_len;

    // Calculate the length of the string "important_config".
    // Note: strlen requires <string.h>, which is typically included for string operations.
    config_len = strlen(important_config); 

    // Open the file for writing.
    // O_CREAT: Create the file if it doesn't exist.
    // O_WRONLY: Open for writing only.
    // O_TRUNC: Truncate the file to zero length if it already exists.
    // 0600: Permissions (rw-------). Owner can read/write, no access for group or others.
    // This explicitly ensures the file is not world-writable.
    fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1) {
        perror("Error opening file");
        return 1; // Indicate an error
    }

    // Write the content of 'important_config' to the file.
    bytes_written = write(fd, important_config, config_len);
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd); // Ensure the file descriptor is closed on error
        return 1; // Indicate an error
    }
    // Check if the full string was written.
    if ((size_t)bytes_written != config_len) {
        fprintf(stderr, "Warning: Not all data was written to the file.\n");
        close(fd);
        return 1; // Indicate an error or partial write
    }

    // Close the file.
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1; // Indicate an error
    }

    printf("Configuration '%s' saved successfully with permissions 0600 (not world-writable).\n", important_config);
    return 0; // Indicate success
}