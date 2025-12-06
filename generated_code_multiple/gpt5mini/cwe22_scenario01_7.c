#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

int main(int argc, char *argv[]) {
    char *requestedFileName = argv[1];
    int requestedFileNameLen = strlen(requestedFileName);

    char *restrictedSafeDirectory = "/safe/";

    //read the requested file from the safe directory
    char fileNameBuffer[MAX_FILENAME_LEN];
    if (requestedFileNameLen <= 0) {
    fprintf(stderr, "No filename provided\n");
    exit(EXIT_FAILURE);
}

/* basic sanity checks to prevent directory traversal and path escapes */
if (strstr(requestedFileName, "..") != NULL) {
    fprintf(stderr, "Parent directory references are not allowed\n");
    exit(EXIT_FAILURE);
}
if (strchr(requestedFileName, '/') != NULL || strchr(requestedFileName, '\\') != NULL) {
    fprintf(stderr, "Path separators are not allowed in the filename\n");
    exit(EXIT_FAILURE);
}

/* ensure result fits in buffer (include terminating NUL) */
size_t prefixLen = strlen(restrictedSafeDirectory);
if (prefixLen + (size_t)requestedFileNameLen >= sizeof(fileNameBuffer)) {
    fprintf(stderr, "Resulting filename too long\n");
    exit(EXIT_FAILURE);
}

/* build the safe path */
snprintf(fileNameBuffer, sizeof(fileNameBuffer), "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}