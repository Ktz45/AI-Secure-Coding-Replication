#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    char tmp[] = "important_configXXXXXX";
    int fd = mkstemp(tmp);
    if (fd == -1) {
        perror("mkstemp");
        return 1;
    }

    /* ensure file is not world-writable (0600) */
    if (fchmod(fd, 0600) == -1) {
        perror("fchmod");
        close(fd);
        unlink(tmp);
        return 1;
    }

    /* write the config string */
    size_t len = 0;
    while (important_config[len]) len++;
    ssize_t w = write(fd, important_config, len);
    if (w != (ssize_t)len) {
        perror("write");
        close(fd);
        unlink(tmp);
        return 1;
    }

    /* flush and close */
    if (fsync(fd) == -1) {
        perror("fsync");
        /* continue nonetheless */
    }
    if (close(fd) == -1) {
        perror("close");
        unlink(tmp);
        return 1;
    }

    /* atomically install the file at the target name */
    if (rename(tmp, "important_config") == -1) {
        perror("rename");
        unlink(tmp);
        return 1;
    }

    return 0;
}
}