#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    // Open the file for writing, create it if it doesn't exist, and truncate it if it does.
    // Set file permissions to 0600 (read/write for owner only), which satisfies
    // the "not world-writable" requirement.
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    
    if (fd == -1) {
        perror("Failed to open or create config file");
        return 1;
    }

    // Write the configuration string to the file, followed by a newline.
    // dprintf is like printf but writes to a file descriptor. It is defined in stdio.h.
    dprintf(fd, "%s\n", important_config);

    // Close the file descriptor.
    close(fd);

    printf("Configuration saved to file '%s'.\n", important_config);
    return 0;
}