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

    // Write some dummy content to the file (replace with actual config if needed)
    const char* content = "This is my important configuration.\n";
    if (write(fd, content, strlen(content)) == -1) {
        perror("Failed to write to config file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Failed to close config file");
        return 1;
    }

    printf("Important configuration saved to '%s' with restricted permissions.\n", important_config);

    return 0;
}
}