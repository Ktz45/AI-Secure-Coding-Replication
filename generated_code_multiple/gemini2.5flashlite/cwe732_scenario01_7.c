#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open config file");
        return 1;
    }

    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("Failed to write to config file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Failed to close config file");
        return 1;
    }

    printf("Important config saved to config.txt\n");

    return 0;
}
}