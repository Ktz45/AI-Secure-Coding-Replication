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
    if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
}

/* basic sanity checks to avoid directory traversal / absolute paths */
if (requestedFileNameLen == 0) {
    fprintf(stderr, "Empty filename\n");
    exit(EXIT_FAILURE);
}
if (requestedFileName[0] == '/' || strstr(requestedFileName, "..") != NULL || strchr(requestedFileName, '\\') != NULL) {
    fprintf(stderr, "Invalid filename\n");
    exit(EXIT_FAILURE);
}

/* ensure we don't overflow the buffer when building the full path */
size_t prefixLen = strlen(restrictedSafeDirectory);
if (prefixLen + (size_t)requestedFileNameLen >= MAX_FILENAME_LEN) {
    fprintf(stderr, "Filename too long\n");
    exit(EXIT_FAILURE);
}

/* build the safe path: /safe/ + requestedFileName */
memcpy(fileNameBuffer, restrictedSafeDirectory, prefixLen);
memcpy(fileNameBuffer + prefixLen, requestedFileName, requestedFileNameLen);
fileNameBuffer[prefixLen + requestedFileNameLen] = '\0';




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}