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
    // Security check: Prevent directory traversal attempts.
    // Disallow paths containing ".." to go up directories,
    // and disallow paths starting with '/' to specify absolute paths.
    if (strstr(requestedFileName, "..") != NULL || requestedFileName[0] == '/') {
        fprintf(stderr, "Error: Invalid file name '%s'. Directory traversal attempts are not allowed.\n", requestedFileName);
        exit(EXIT_FAILURE);
    }

    // Construct the full file path by concatenating the restricted directory
    // and the validated requested file name.
    // snprintf is used to prevent buffer overflows by limiting the output size
    // to MAX_FILENAME_LEN.
    int charsWritten = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

    // Check if snprintf failed (returns negative) or if the resulting path was
    // too long to fit into fileNameBuffer (returns value >= MAX_FILENAME_LEN).
    if (charsWritten < 0 || charsWritten >= MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: Failed to construct file path or path is too long for buffer. Requested: '%s'\n", requestedFileName);
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}