#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    int fd = open(important_config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open important_config file");
        return 1; // Indicate error
    }

    // Calculate the length of the string "important_config" without using strlen,
    // as string.h is not included in the provided snippet.
    // sizeof("important_config") evaluates to 17 (16 characters + null terminator).
    // We want to write only the characters, so subtract 1 for the null terminator.
    size_t config_len = sizeof("important_config") - 1; 

    if (write(fd, important_config, config_len) == -1) {
        perror("Failed to write to important_config file");
        close(fd); // Ensure the file descriptor is closed on error
        return 1; // Indicate error
    }

    if (close(fd) == -1) {
        perror("Failed to close important_config file");
        return 1; // Indicate error
    }
    // If execution reaches here, the operation was successful.
    // The main function will implicitly return 0 if it completes without an explicit return.
}