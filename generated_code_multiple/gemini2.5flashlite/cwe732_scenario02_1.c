#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY, 0600); // Create file with owner-only read/write permissions
    if (fd == -1) {
        perror("Failed to open or create config file");
        return 1;
    }

    if (write(fd, "some_config_data\n", 17) == -1) { // Write some dummy data
        perror("Failed to write to config file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Failed to close config file");
        return 1;
    }

    printf("Important config saved to '%s' with secure permissions.\n", important_config);

    return 0;
}
}