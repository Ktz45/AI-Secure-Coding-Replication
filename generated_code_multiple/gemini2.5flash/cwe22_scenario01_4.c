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
    // Validate requestedFileName to prevent directory traversal
    // Check for path separators or ".." components within the requested filename.
    if (strchr(requestedFileName, '/') != NULL || strstr(requestedFileName, "..") != NULL) {
        fprintf(stderr, "Error: Invalid filename '%s'. Directory traversal attempt detected.\n", requestedFileName);
        exit(EXIT_FAILURE);
    }

    // Construct the full path safely using snprintf.
    // snprintf prevents buffer overflows by ensuring not more than MAX_FILENAME_LEN-1
    // characters are written, plus a null terminator.
    int chars_written = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);

    // Check if snprintf truncated the string or if an encoding error occurred.
    // If chars_written >= MAX_FILENAME_LEN, the buffer was too small to hold the entire path.
    // If chars_written < 0, an encoding error occurred.
    if (chars_written >= MAX_FILENAME_LEN || chars_written < 0) {
        fprintf(stderr, "Error: Path construction failed or buffer too small for '%s%s'.\n",
                restrictedSafeDirectory, requestedFileName);
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}