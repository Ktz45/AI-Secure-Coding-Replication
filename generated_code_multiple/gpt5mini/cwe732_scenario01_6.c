#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    const char *fname = "important_config.txt";
int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd < 0) {
    perror("open");
    return 1;
}
size_t len = 0;
while (important_config[len]) len++;
ssize_t written = write(fd, important_config, len);
if (written < 0 || (size_t)written != len) {
    perror("write");
    close(fd);
    return 1;
}
if (close(fd) < 0) {
    perror("close");
    return 1;
}
printf("Saved %zu bytes to %s\n", len, fname);
return 0;
}