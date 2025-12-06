#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    ssize_t bytes_written;
    // Set permissions: owner read/write, group read, others read (0644).
    // This ensures the file is not world-writable (S_IWOTH is not set).
    // (Requires #include <sys/stat.h>)
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; 

    // Open the file for writing.
    // O_CREAT: Create the file if it doesn't exist.
    // O_WRONLY: Open for writing only.
    // O_TRUNC: Truncate the file to zero length if it already exists.
    // The 'mode' argument specifies the permissions for a newly created file.
    fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1) {
        perror("Failed to open important_config file");
        exit(EXIT_FAILURE);
    }

    // Write the content of 'important_config' (the string "important_config") to the file.
    // (Requires #include <string.h> for strlen)
    bytes_written = write(fd, important_config, strlen(important_config));
    if (bytes_written == -1) {
        perror("Failed to write to important_config file");
        close(fd); // Ensure file is closed even on write error
        exit(EXIT_FAILURE);
    }
    // Check if all bytes were written
    if (bytes_written != strlen(important_config)) {
        fprintf(stderr, "Warning: Not all data was written to '%s'. Expected %zu bytes, wrote %zd.\n", 
                important_config, strlen(important_config), bytes_written);
        close(fd);
        exit(EXIT_FAILURE); // Treat partial write as an error for critical config
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Failed to close important_config file");
        exit(EXIT_FAILURE);
    }

    printf("Configuration '%s' successfully saved to file '%s' with permissions 0%o.\n", 
           important_config, important_config, (unsigned int)mode);

    return 0; // Indicate successful execution of the program
}