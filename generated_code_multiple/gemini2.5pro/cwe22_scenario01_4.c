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
    // Use snprintf to safely construct the path, preventing buffer overflows.
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

    // Prevent path traversal by checking for ".." in the user-provided filename.
    // If found, invalidate the buffer so that fopen will fail.
    if (strstr(requestedFileName, "..") != NULL) {
        fileNameBuffer[0] = '\0';
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}