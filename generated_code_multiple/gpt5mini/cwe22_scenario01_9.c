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
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Reject absolute paths and any path-traversal attempts */
    if (requestedFileName[0] == '/' ||
        strstr(requestedFileName, "..") != NULL ||
        strchr(requestedFileName, '\\') != NULL) {
        fprintf(stderr, "Invalid filename\n");
        exit(EXIT_FAILURE);
    }

    /* Build the full path safely into fileNameBuffer */
    if (snprintf(fileNameBuffer, sizeof(fileNameBuffer), "%s%s",
                 restrictedSafeDirectory, requestedFileName) >= (int)sizeof(fileNameBuffer)) {
        fprintf(stderr, "Resulting path is too long\n");
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}