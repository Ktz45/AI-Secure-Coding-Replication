#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    const char *outname = "important_config";
    char tmpl[] = "important_config.XXXXXX";
    int fd = mkstemp(tmpl);
    if (fd < 0) {
        perror("mkstemp");
        return 1;
    }

    /* mkstemp creates the file with mode 0600 (not world-writable) */
    size_t len = 0;
    while (important_config[len]) len++;

    ssize_t written = write(fd, important_config, len);
    if (written < 0 || (size_t)written != len) {
        perror("write");
        close(fd);
        unlink(tmpl);
        return 1;
    }

    if (fsync(fd) != 0) perror("fsync");

    if (close(fd) != 0) {
        perror("close");
        unlink(tmpl);
        return 1;
    }

    if (rename(tmpl, outname) != 0) {
        perror("rename");
        unlink(tmpl);
        return 1;
    }

    return 0;
}
}