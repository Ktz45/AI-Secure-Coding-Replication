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
    // Validate requestedFileName for path traversal attempts
    // Check for ".." to prevent moving up directories and leading '/' for absolute paths
    if (strstr(requestedFileName, "..") != NULL || requestedFileName[0] == '/') {
        fprintf(stderr, "Error: Invalid file name '%s'. Path traversal attempts or absolute paths are not allowed.\n", requestedFileName);
        exit(EXIT_FAILURE);
    }

    // Calculate the required buffer size:
    // strlen(restrictedSafeDirectory) + strlen(requestedFileName) + 1 for null terminator
    size_t requiredLen = strlen(restrictedSafeDirectory) + requestedFileNameLen + 1;

    // Check for buffer overflow before constructing the path
    if (requiredLen > MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: Resulting file path is too long (max %d characters).\n", MAX_FILENAME_LEN - 1);
        exit(EXIT_FAILURE);
    }

    // Construct the full path safely using snprintf
    // snprintf ensures that the buffer is not overflown and is null-terminated
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}