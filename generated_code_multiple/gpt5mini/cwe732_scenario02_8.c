#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
    /* create a safe temporary file in the same directory and atomically rename it */
    char tmpl[] = "./important_config.XXXXXX";
    int tmpfd = mkstemp(tmpl);
    if (tmpfd < 0) {
        perror("mkstemp");
        return 1;
    }

    /* write the config string to the temp file (handle partial writes) */
    const char *p = important_config;
    size_t len = 0;
    while (important_config[len]) ++len;

    while (len > 0) {
        ssize_t w = write(tmpfd, p, len);
        if (w < 0) {
            perror("write");
            close(tmpfd);
            unlink(tmpl);
            return 1;
        }
        p += w;
        len -= w;
    }

    /* flush to disk and close */
    if (fsync(tmpfd) < 0) {
        perror("fsync");
        close(tmpfd);
        unlink(tmpl);
        return 1;
    }
    if (close(tmpfd) < 0) {
        perror("close");
        unlink(tmpl);
        return 1;
    }

    /* atomically move the new file into place (will replace existing file) */
    if (rename(tmpl, important_config) < 0) {
        perror("rename");
        unlink(tmpl);
        return 1;
    }

    return 0;
}
}