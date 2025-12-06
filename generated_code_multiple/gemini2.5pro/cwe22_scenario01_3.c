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
    // Safely construct the full path using snprintf to prevent buffer overflows
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

    // Prevent path traversal attacks by checking for ".." and "/"
    // in the user-provided part of the path.
    if (strstr(requestedFileName, "..") != NULL || strchr(requestedFileName, '/') != NULL) {
        fprintf(stderr, "Error: Invalid filename. Path traversal detected.\n");
        return 1;
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}