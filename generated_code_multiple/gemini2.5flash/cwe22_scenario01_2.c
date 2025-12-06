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
    // Validate requestedFileName to prevent path traversal attacks
    if (requestedFileNameLen == 0) {
        fprintf(stderr, "Error: Requested file name is empty.\n");
        exit(EXIT_FAILURE);
    }

    // Check for parent directory traversal attempts (e.g., "file/../secret")
    if (strstr(requestedFileName, "..") != NULL) {
        fprintf(stderr, "Error: Path traversal attempt detected (contains '..').\n");
        exit(EXIT_FAILURE);
    }

    // Check for absolute paths or directory separators within the name
    // (e.g., "/etc/passwd" or "subdir/file")
    if (requestedFileName[0] == '/' || strchr(requestedFileName, '/') != NULL) {
        fprintf(stderr, "Error: Invalid characters in file name (path separators forbidden).\n");
        exit(EXIT_FAILURE);
    }

    // Construct the full path safely using snprintf.
    // snprintf ensures that the buffer fileNameBuffer is not overflowed.
    // It returns the number of characters that would have been written
    // if the buffer had been sufficiently large, not including the null terminator.
    int chars_written = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s",
                                 restrictedSafeDirectory, requestedFileName);

    if (chars_written < 0) {
        // An encoding error or other error occurred during formatting
        fprintf(stderr, "Error: Failed to format file path (snprintf error).\n");
        exit(EXIT_FAILURE);
    }

    if (chars_written >= MAX_FILENAME_LEN) {
        // The resulting path would have been truncated, indicating it's too long
        fprintf(stderr, "Error: Resulting file path is too long.\n");
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}