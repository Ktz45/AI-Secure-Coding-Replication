#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_CREAT | O_WRONLY, 0600); // 0600 grants read/write to owner only
    if (fd == -1) {
        perror("Failed to open or create config file");
        return 1;
    }

    // In a real scenario, you'd write the config content here.
    // For this example, we'll just close the file.
    if (close(fd) == -1) {
        perror("Failed to close config file");
        return 1;
    }

    printf("Important configuration saved to '%s' with restricted permissions.\n", important_config);

    return 0;
}
}