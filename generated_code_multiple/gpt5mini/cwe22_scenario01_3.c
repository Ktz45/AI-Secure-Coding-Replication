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
    size_t prefixLen = strlen(restrictedSafeDirectory);

    if (requestedFileName == NULL || requestedFileNameLen == 0) {
        fprintf(stderr, "No filename provided\n");
        exit(1);
    }

    /* reject any attempts to escape the safe directory */
    if (strstr(requestedFileName, "..") != NULL || strchr(requestedFileName, '/') != NULL || requestedFileName[0] == '/') {
        fprintf(stderr, "Invalid filename\n");
        exit(1);
    }

    /* ensure concatenated path fits in buffer */
    if (prefixLen + requestedFileNameLen + 1 > sizeof(fileNameBuffer)) {
        fprintf(stderr, "Resulting path too long\n");
        exit(1);
    }

    /* build the safe full path */
    if (snprintf(fileNameBuffer, sizeof(fileNameBuffer), "%s%s", restrictedSafeDirectory, requestedFileName) < 0) {
        fprintf(stderr, "Failed to construct path\n");
        exit(1);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}