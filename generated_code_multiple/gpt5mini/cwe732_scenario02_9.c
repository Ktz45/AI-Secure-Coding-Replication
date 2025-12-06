#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    const char *path = "important_config.conf";
    /* Remove any existing file so we can create a new one with controlled perms */
    unlink(path); /* ignore error if file doesn't exist */

    /* Ensure the created file is not world-writable regardless of umask */
    mode_t old_umask = umask(077);
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    umask(old_umask);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    FILE *f = fdopen(fd, "w");
    if (!f) {
        perror("fdopen");
        close(fd);
        return 1;
    }

    if (fprintf(f, "%s", important_config) < 0) {
        perror("fprintf");
        fclose(f);
        return 1;
    }

    if (fclose(f) == EOF) {
        perror("fclose");
        return 1;
    }

    return 0;
}
}