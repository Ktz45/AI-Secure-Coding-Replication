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
    size_t restrictedSafeDirectoryLen = strlen(restrictedSafeDirectory);

    // Calculate the required length for the full path including the null terminator
    // Cast requestedFileNameLen to size_t for consistent type arithmetic with strlen results
    size_t requiredPathLen = restrictedSafeDirectoryLen + (size_t)requestedFileNameLen + 1;

    // Check for buffer overflow before attempting to construct the path
    if (requiredPathLen > MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: Resulting file path is too long. Max allowed length for filename part is %zu characters.\n", MAX_FILENAME_LEN - restrictedSafeDirectoryLen - 1);
        exit(EXIT_FAILURE);
    }

    // Construct the full path safely using snprintf
    // snprintf ensures null termination and prevents writing beyond MAX_FILENAME_LEN-1 characters.
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}