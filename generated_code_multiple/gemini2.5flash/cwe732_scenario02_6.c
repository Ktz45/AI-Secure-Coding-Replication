#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, 0600); // 0600 ensures rw------- permissions (owner read/write, no group/other access)
    if (fd == -1) {
        perror("Failed to open important_config file");
        exit(EXIT_FAILURE);
    }

    // Write the content of the 'important_config' string to the file
    // Note: strlen() requires #include <string.h>, which should be added at the top of the file.
    const char* config_content = important_config;
    size_t content_len = strlen(config_content); 

    ssize_t bytes_written = write(fd, config_content, content_len);
    if (bytes_written == -1) {
        perror("Failed to write to important_config file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if (bytes_written < content_len) {
        fprintf(stderr, "Warning: Not all config data was written to file.\n");
    }

    close(fd);
}