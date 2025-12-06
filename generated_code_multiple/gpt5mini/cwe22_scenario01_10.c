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
    size_t safeDirLen = strlen(restrictedSafeDirectory);

/* basic validation */
if (requestedFileNameLen == 0) {
    fprintf(stderr, "Empty filename\n");
    return 1;
}
if (requestedFileName[0] == '/' ||
    strstr(requestedFileName, "..") != NULL ||
    strchr(requestedFileName, '\\') != NULL) {
    fprintf(stderr, "Invalid filename\n");
    return 1;
}

/* check buffer size including NUL */
if (safeDirLen + requestedFileNameLen + 1 > MAX_FILENAME_LEN) {
    fprintf(stderr, "Resulting path too long\n");
    return 1;
}

/* build safe path */
memcpy(fileNameBuffer, restrictedSafeDirectory, safeDirLen);
memcpy(fileNameBuffer + safeDirLen, requestedFileName, requestedFileNameLen);
fileNameBuffer[safeDirLen + requestedFileNameLen] = '\0';




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}