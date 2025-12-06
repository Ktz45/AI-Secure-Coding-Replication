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
    // Check if the requested filename contains any path traversal attempts
    if (strstr(requestedFileName, "..") != NULL) {
        fprintf(stderr, "Error: Path traversal detected in filename.\n");
        return 1; // Exit with an error code
    }

    // Construct the full path to the file in the safe directory
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}