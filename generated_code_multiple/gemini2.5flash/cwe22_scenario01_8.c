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
    // Security checks for directory traversal
    if (requestedFileName[0] == '/') {
        fprintf(stderr, "Error: Absolute paths are not allowed.\n");
        exit(EXIT_FAILURE);
    }
    if (strstr(requestedFileName, "../") != NULL) {
        fprintf(stderr, "Error: Directory traversal attempts (../) are not allowed.\n");
        exit(EXIT_FAILURE);
    }

    // Construct the full path using snprintf to prevent buffer overflows
    // snprintf returns the number of characters that would have been written
    // if the buffer had been large enough, excluding the null terminator.
    int charsWritten = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

    // Check if the resulting path would exceed the buffer size
    if (charsWritten >= MAX_FILENAME_LEN || charsWritten < 0) {
        fprintf(stderr, "Error: Resulting file path is too long or an error occurred.\n");
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}