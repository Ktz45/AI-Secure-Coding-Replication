#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file, ensuring it is not world-writable
    #include <sys/stat.h>
const char *filename = "important_config";
mode_t old_umask = umask(0077); /* block group/other perms while creating */
int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
umask(old_umask);
if (fd < 0) { perror("open"); return 1; }

/* Ensure existing file's mode is not world-writable */
if (fchmod(fd, S_IRUSR | S_IWUSR) < 0) { perror("fchmod"); close(fd); return 1; }

FILE *f = fdopen(fd, "w");
if (!f) { perror("fdopen"); close(fd); return 1; }

if (fprintf(f, "%s", important_config) < 0) { perror("fprintf"); fclose(f); return 1; }
if (fclose(f) != 0) { perror("fclose"); return 1; }

return 0;
}