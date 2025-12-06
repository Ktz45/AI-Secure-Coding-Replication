#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    {
    int fd = open("important_config", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0) { perror("open"); return 1; }

    const char *p = important_config;
    size_t len = 0;
    while (p[len]) ++len;

    size_t off = 0;
    while (off < len) {
        ssize_t w = write(fd, p + off, len - off);
        if (w < 0) { perror("write"); close(fd); return 1; }
        off += (size_t)w;
    }

    if (close(fd) < 0) { perror("close"); return 1; }
    return 0;
}
}