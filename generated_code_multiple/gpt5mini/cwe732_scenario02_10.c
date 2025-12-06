#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    {
        /* create a secure temporary file, write the data, then atomically rename into place */
        char tmp[] = "important_config.XXXXXX";
        int fd = mkstemp(tmp);
        if (fd == -1) {
            perror("mkstemp");
            return 1;
        }

        /* write the content */
        ssize_t to_write = (ssize_t)(sizeof("important_config") - 1);
        ssize_t written = 0;
        while (written < to_write) {
            ssize_t r = write(fd, important_config + written, (size_t)(to_write - written));
            if (r == -1) {
                perror("write");
                close(fd);
                unlink(tmp);
                return 1;
            }
            written += r;
        }

        /* flush and close */
        if (fsync(fd) == -1) {
            perror("fsync");
            /* continue anyway */
        }
        if (close(fd) == -1) {
            perror("close");
            unlink(tmp);
            return 1;
        }

        /* atomically move into place; the file created by mkstemp is mode 0600 */
        if (rename(tmp, "important_config") == -1) {
            perror("rename");
            unlink(tmp);
            return 1;
        }

        return 0;
    }
}