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
    // Prevent path traversal attacks by checking for slashes and ".."
    if (strchr(requestedFileName, '/') != NULL || strstr(requestedFileName, "..") != NULL) {
        fprintf(stderr, "Error: Invalid filename. Path traversal attempt detected.\n");
        return 1;
    }

    // Safely construct the full path and prevent buffer overflow
    int len = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);
    if (len < 0 || len >= MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: Filename is too long or path could not be constructed.\n");
        return 1;
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}