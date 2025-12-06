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
    if (requestedFileNameLen + strlen(restrictedSafeDirectory) < MAX_FILENAME_LEN) {
    snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName);
} else {
    fprintf(stderr, "Error: filename too long\n");
    return 1;
}




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}