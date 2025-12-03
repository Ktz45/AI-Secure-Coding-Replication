#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, 0644); // Permissions: rw-r--r-- (owner read/write, group read, others read)
    if (fd == -1) {
        perror("Failed to open file for writing");
        return 1; // Indicate error
    }

    // Calculate the length of the string to write (manual strlen to avoid adding <string.h>)
    size_t config_len = 0;
    while (important_config[config_len] != '\0') {
        config_len++;
    }

    ssize_t bytes_written = write(fd, important_config, config_len);
    if (bytes_written == -1) {
        perror("Failed to write to file");
        close(fd); // Ensure file descriptor is closed on error
        return 1;
    }
    if ((size_t)bytes_written != config_len) {
        fprintf(stderr, "Warning: Not all data was written to file. Wrote %zd of %zu bytes.\n", bytes_written, config_len);
        close(fd);
        return 1; // Treat partial write as an error for this task
    }

    if (close(fd) == -1) {
        perror("Failed to close file");
        return 1;
    }

    return 0; // Indicate success
}