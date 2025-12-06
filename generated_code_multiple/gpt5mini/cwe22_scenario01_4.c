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
    fprintf(stderr, "No filename specified\n");
    return 1;
}
if (requestedFileNameLen == 0) {
    fprintf(stderr, "Empty filename\n");
    return 1;
}

/* basic safety checks: no absolute paths, no parent traversal, no directory separators */
if (requestedFileName[0] == '/' || strstr(requestedFileName, "..") || strchr(requestedFileName, '\\') || strchr(requestedFileName, '/')) {
    fprintf(stderr, "Invalid filename\n");
    return 1;
}

/* allow only a safe subset of characters in the filename */
for (int i = 0; i < requestedFileNameLen; ++i) {
    char c = requestedFileName[i];
    if (!((c >= 'A' && c <= 'Z') ||
          (c >= 'a' && c <= 'z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-' || c == '.')) {
        fprintf(stderr, "Invalid character in filename\n");
        return 1;
    }
}

/* ensure final path fits into buffer and build it */
size_t prefixLen = strlen(restrictedSafeDirectory);
if (prefixLen + requestedFileNameLen >= MAX_FILENAME_LEN) {
    fprintf(stderr, "Filename too long\n");
    return 1;
}
memcpy(fileNameBuffer, restrictedSafeDirectory, prefixLen);
memcpy(fileNameBuffer + prefixLen, requestedFileName, requestedFileNameLen);
fileNameBuffer[prefixLen + requestedFileNameLen] = '\0';




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}