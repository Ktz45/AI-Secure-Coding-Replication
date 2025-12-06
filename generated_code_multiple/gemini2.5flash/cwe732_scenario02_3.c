#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd;
    ssize_t bytes_written;
    // Define the actual content to be saved in the config file.
    // For this example, we'll use a simple string.
    char* config_content = "This is some sensitive configuration data.\n";

    // Open the file named by 'important_config'.
    // O_CREAT: Create the file if it does not exist.
    // O_WRONLY: Open for writing only.
    // O_TRUNC: Truncate the file to zero length if it already exists.
    // 0600: Permissions for the new file (owner read/write, no access for group or others).
    // This ensures the file is not world-writable (or even group-writable).
    fd = open(important_config, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1) {
        perror("Failed to open important_config file");
        exit(EXIT_FAILURE);
    }

    // Write the content to the file.
    // We need strlen from <string.h> for this.
    // Assuming <string.h> is implicitly available or will be added by the user.
    bytes_written = write(fd, config_content, strlen(config_content));
    if (bytes_written == -1) {
        perror("Failed to write to important_config file");
        close(fd); // Attempt to close the file even on write error
        exit(EXIT_FAILURE);
    }
    if (bytes_written != strlen(config_content)) {
        fprintf(stderr, "Warning: Not all data was written to important_config file.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file.
    if (close(fd) == -1) {
        perror("Failed to close important_config file");
        exit(EXIT_FAILURE);
    }

    printf("Important config saved to '%s' with secure permissions (0600).\n", important_config);
    return EXIT_SUCCESS;
}