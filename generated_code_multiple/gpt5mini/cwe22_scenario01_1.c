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
    if (requestedFileName == NULL) {
    fprintf(stderr, "No filename provided\n");
    exit(EXIT_FAILURE);
}

/* disallow absolute paths, parent-directory traversal and any path separators */
if (requestedFileName[0] == '/' ||
    strstr(requestedFileName, "..") != NULL ||
    strchr(requestedFileName, '/') != NULL) {
    fprintf(stderr, "Invalid filename\n");
    exit(EXIT_FAILURE);
}

/* ensure the combined path fits into the buffer */
int n = snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);
if (n < 0 || n >= MAX_FILENAME_LEN) {
    fprintf(stderr, "Resulting filename is too long\n");
    exit(EXIT_FAILURE);
}




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}