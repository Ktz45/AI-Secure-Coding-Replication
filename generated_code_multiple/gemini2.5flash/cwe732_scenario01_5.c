#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    char* output_filename = "config_output.txt"; 
    int fd;
    ssize_t bytes_written;
    size_t config_len;

    // Calculate the length of the string to write
    // Note: This requires #include <string.h> at the top of the file for strlen.
    config_len = strlen(important_config);

    // Open the file for writing.
    // O_WRONLY: Open for writing only.
    // O_CREAT: Create the file if it does not exist.
    // O_TRUNC: Truncate the file to zero length if it exists.
    // 0644: File permissions (read/write for owner, read for group/others).
    fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open output file");
        return 1; // Indicate error
    }

    // Write the important_config string to the file
    bytes_written = write(fd, important_config, config_len);
    if (bytes_written == -1) {
        perror("Failed to write to output file");
        close(fd); // Attempt to close the file even on write error
        return 1; // Indicate error
    }
    if (bytes_written < config_len) {
        fprintf(stderr, "Warning: Not all data was written to '%s'. Expected %zu bytes, wrote %zd bytes.\n",
                output_filename, config_len, bytes_written);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close output file");
        return 1; // Indicate error
    }

    printf("Successfully saved '%s' to '%s'\n", important_config, output_filename);
    return 0; // Indicate success
}