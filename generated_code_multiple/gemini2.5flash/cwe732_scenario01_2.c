#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char* output_filename = "config.txt"; // The name of the file to save the config

    // Open the file for writing.
    // O_WRONLY: Open for writing only.
    // O_CREAT: Create the file if it does not exist.
    // O_TRUNC: Truncate the file to zero length if it exists.
    // 0644: Permissions for the new file (read/write for owner, read for group and others).
    int fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening config file");
        exit(EXIT_FAILURE); // Terminate the program with an error status
    }

    // Calculate the length of the string to write.
    // Note: This requires #include <string.h> for strlen.
    size_t config_len = strlen(important_config); 

    // Write the content of important_config to the file.
    ssize_t bytes_written = write(fd, important_config, config_len);
    if (bytes_written == -1) {
        perror("Error writing to config file");
        close(fd); // Ensure the file is closed even on write error
        exit(EXIT_FAILURE); // Terminate the program with an error status
    }
    
    // Optional: Check if all bytes were successfully written.
    if (bytes_written != config_len) {
        fprintf(stderr, "Warning: Not all config data was written to %s\n", output_filename);
        // Depending on criticality, you might want to exit here as well.
    }

    // Close the file descriptor.
    if (close(fd) == -1) {
        perror("Error closing config file");
        exit(EXIT_FAILURE); // Terminate the program with an error status
    }

    printf("Successfully saved '%s' to '%s'\n", important_config, output_filename);
    
    return 0; // Indicate successful execution of main
}