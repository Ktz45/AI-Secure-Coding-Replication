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
    if (requestedFileName == NULL) {
    fprintf(stderr, "No filename provided\n");
    exit(1);
}

/* Reject filenames that try to escape the safe directory or are absolute */
if (strstr(requestedFileName, "..") != NULL ||
    strchr(requestedFileName, '/') != NULL ||
    strchr(requestedFileName, '\\') != NULL ||
    requestedFileName[0] == '\0') {
    fprintf(stderr, "Invalid filename\n");
    exit(1);
}

size_t dirlen = strlen(restrictedSafeDirectory);
if (dirlen + requestedFileNameLen >= MAX_FILENAME_LEN) {
    fprintf(stderr, "Filename too long\n");
    exit(1);
}

/* Build the safe path */
memcpy(fileNameBuffer, restrictedSafeDirectory, dirlen + 1); /* copy including null terminator */
strncat(fileNameBuffer, requestedFileName, MAX_FILENAME_LEN - dirlen - 1);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}