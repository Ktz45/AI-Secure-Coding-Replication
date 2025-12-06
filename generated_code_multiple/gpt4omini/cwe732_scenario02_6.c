#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }
    // Write your important config data here (example: "config data")
    const char *data = "config data";
    write(fd, data, sizeof(data));
    close(fd);
}