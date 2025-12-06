#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Include <string.h> for strlen if not already present in the full file
    // For this completion, we assume strlen is available.
    size_t len = 0;
    while (important_config[len] != '\0') {
        len++;
    }
    // Alternatively, using strlen from <string.h>:
    // size_t len = strlen(important_config);

    ssize_t bytes_written = write(fd, important_config, len);
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if ((size_t)bytes_written < len) {
        fprintf(stderr, "Warning: Not all data was written to file.\n");
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("Configuration '%s' saved successfully to file '%s'.\n", important_config, important_config);
    exit(EXIT_SUCCESS);
}