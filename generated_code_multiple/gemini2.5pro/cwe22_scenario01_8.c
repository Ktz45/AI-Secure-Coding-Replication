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
    // Sanitize the filename by extracting only the base name to prevent path traversal.
    char *base_filename = strrchr(requestedFileName, '/');
    if (base_filename == NULL) {
        base_filename = requestedFileName;
    } else {
        base_filename++; // Move pointer to the character after the last '/'
    }

    // Safely construct the full path, preventing buffer overflows.
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, base_filename);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}