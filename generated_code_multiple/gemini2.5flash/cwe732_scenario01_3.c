#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    #include <string.h> // Required for strlen

    int fd;
    const char* filename = "config.txt"; // Define the output file name

    // Open the file for writing.
    // O_WRONLY: Write only
    // O_CREAT: Create the file if it does not exist
    // O_TRUNC: Truncate the file to zero length if it exists
    // 0644: Permissions (owner read/write, group read, others read)
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the length of the string to write
    size_t config_len = strlen(important_config);

    // Write the string to the file
    ssize_t bytes_written = write(fd, important_config, config_len);

    // Check for write errors
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd); // Ensure the file is closed
        exit(EXIT_FAILURE);
    }

    // Check if all data was written
    if ((size_t)bytes_written < config_len) {
        fprintf(stderr, "Warning: Not all config data was written to '%s'. Only %zd of %zu bytes written.\n",
                filename, bytes_written, config_len);
        close(fd);
        exit(EXIT_FAILURE); // Consider this an error for critical config
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("Important config '%s' successfully saved to '%s'\n", important_config, filename);
}