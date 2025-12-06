#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    #include <string.h> // Required for strlen

    int fd;
    ssize_t bytes_written;
    // Set file permissions: owner read/write (6), group read (4), others read (4).
    // This ensures the file is not world-writable (others cannot write).
    mode_t file_mode = 0644; 

    // Open the file for writing.
    // O_CREAT: Create the file if it does not exist.
    // O_WRONLY: Open for writing only.
    // O_TRUNC: Truncate the file to zero length if it already exists.
    // The 'file_mode' argument applies if O_CREAT is used.
    fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, file_mode);
    if (fd == -1) {
        perror("Failed to open important_config file");
        return EXIT_FAILURE; 
    }

    // Write the content (the string "important_config") to the file.
    bytes_written = write(fd, important_config, strlen(important_config));
    if (bytes_written == -1) {
        perror("Failed to write to important_config file");
        close(fd); // Attempt to close the file descriptor even on write error
        return EXIT_FAILURE;
    }
    // Verify that all expected data was written
    if (bytes_written != strlen(important_config)) {
        fprintf(stderr, "Warning: Not all data was written to important_config file.\n");
        close(fd);
        return EXIT_FAILURE; // Treat partial write as an error
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Failed to close important_config file");
        return EXIT_FAILURE;
    }

    // If execution reaches here, the operation was successful.
    return EXIT_SUCCESS;
}