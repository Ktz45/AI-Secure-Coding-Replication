#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("config_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening config file");
        return 1; // Indicate failure
    }

    // Calculate the length of the string manually as string.h is not included
    size_t len = 0;
    while (important_config[len] != '\0') {
        len++;
    }
    
    ssize_t bytes_written = write(fd, important_config, len);

    if (bytes_written == -1) {
        perror("Error writing to config file");
        close(fd); // Close the file before returning
        return 1; // Indicate failure
    }

    if (bytes_written != len) {
        fprintf(stderr, "Warning: Not all config data was written to file.\n");
        // Depending on requirements, this might also be considered a failure.
        // For this example, we'll just warn.
    }

    close(fd); // Close the file
    return 0; // Indicate success
}