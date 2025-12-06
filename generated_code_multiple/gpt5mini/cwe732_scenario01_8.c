#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char *filename = "important_config.txt";
int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd < 0) {
    perror("open");
    return 1;
}

/* compute length without <string.h> */
size_t len = 0;
while (important_config[len]) len++;

size_t written = 0;
while (written < len) {
    ssize_t n = write(fd, important_config + written, len - written);
    if (n < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    written += (size_t)n;
}

if (close(fd) < 0) {
    perror("close");
    return 1;
}

printf("Saved config to %s\n", filename);
return 0;
}