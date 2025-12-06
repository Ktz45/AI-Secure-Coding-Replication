#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY, 0600);
    if (fd == -1) {
        perror("Failed to open/create config file");
        return 1;
    }

    // Write some dummy content to the file
    const char* config_content = "This is some important configuration data.\n";
    if (write(fd, config_content, strlen(config_content)) == -1) {
        perror("Failed to write to config file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Failed to close config file");
        return 1;
    }

    printf("Important config saved to '%s' with restricted permissions.\n", important_config);

    return 0;
}
}