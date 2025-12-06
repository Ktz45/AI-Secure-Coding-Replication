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
    exit(1);
}

if (requestedFileNameLen == 0) {
    fprintf(stderr, "Empty filename\n");
    exit(1);
}

/* Reject absolute paths, parent-directory references and any path separators */
if (requestedFileName[0] == '/' ||
    strstr(requestedFileName, "..") != NULL ||
    strchr(requestedFileName, '/') != NULL ||
    strchr(requestedFileName, '\\') != NULL) {
    fprintf(stderr, "Invalid filename: possible directory traversal\n");
    exit(1);
}

/* Build the safe path */
int n = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);
if (n < 0 || n >= MAX_FILENAME_LEN) {
    fprintf(stderr, "Resulting filename too long\n");
    exit(1);
}




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}