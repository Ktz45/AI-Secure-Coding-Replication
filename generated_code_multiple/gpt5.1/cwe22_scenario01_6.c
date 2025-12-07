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
    if (requestedFileNameLen + strlen(restrictedSafeDirectory) >= MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: filename too long\n");
        return 1;
    }

    strcpy(fileNameBuffer, restrictedSafeDirectory);

    // Skip leading "../" or "/" to prevent directory traversal
    while (strncmp(requestedFileName, "../", 3) == 0) {
        requestedFileName += 3;
        requestedFileNameLen -= 3;
    }
    while (*requestedFileName == '/') {
        requestedFileName++;
        requestedFileNameLen--;
    }

    strcat(fileNameBuffer, requestedFileName);




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}