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
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
}

/* Reject absolute paths and path traversal or embedded slashes */
if (requestedFileName[0] == '/' ||
    strstr(requestedFileName, "..") != NULL ||
    strchr(requestedFileName, '/') != NULL) {
    fprintf(stderr, "Invalid filename\n");
    return 1;
}

/* Ensure the combined path fits into the buffer */
if ((size_t)requestedFileNameLen + strlen(restrictedSafeDirectory) + 1 > MAX_FILENAME_LEN) {
    fprintf(stderr, "Resulting path too long\n");
    return 1;
}

/* Construct the full path inside the safe directory */
snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}