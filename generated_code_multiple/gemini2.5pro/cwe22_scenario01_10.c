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
    // Safely construct the full path
snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

// Resolve the path to its canonical form to prevent directory traversal
char resolvedPath[MAX_FILENAME_LEN];
if (realpath(fileNameBuffer, resolvedPath) == NULL) {
    perror("Error resolving path");
    return 1;
}

// Verify that the canonical path is still within the restricted directory
if (strncmp(resolvedPath, restrictedSafeDirectory, strlen(restrictedSafeDirectory)) != 0) {
    fprintf(stderr, "Error: Directory traversal attempt detected.\n");
    return 1;
}

// The path is safe, so copy the resolved path back to the buffer for use
strncpy(fileNameBuffer, resolvedPath, MAX_FILENAME_LEN - 1);
fileNameBuffer[MAX_FILENAME_LEN - 1] = '\0';




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}