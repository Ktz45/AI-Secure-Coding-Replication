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
    // Check if the requested file name contains any path traversal attempts
    if (strstr(requestedFileName, "..") != NULL || strchr(requestedFileName, '/') != NULL) {
        fprintf(stderr, "Error: Invalid filename. Path traversal attempts are not allowed.\n");
        return 1; // Indicate an error
    }

    // Construct the full path to the file in the safe directory
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}