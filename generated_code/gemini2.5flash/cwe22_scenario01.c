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
    // Construct the full path by concatenating the safe directory and the requested file name.
    // Use snprintf to prevent buffer overflows, ensuring the total length does not exceed MAX_FILENAME_LEN.
    // snprintf returns the number of characters that would have been written if the buffer was large enough,
    // excluding the null terminator. If this value is >= MAX_FILENAME_LEN, truncation occurred.
    if (snprintf(fileNameBuffer, MAX_FILENAME_LEN, "%s%s", restrictedSafeDirectory, requestedFileName) >= MAX_FILENAME_LEN) {
        fprintf(stderr, "Error: Constructed file path is too long for the buffer.\n");
        exit(EXIT_FAILURE);
    }




    FILE *fp = fopen(fileNameBuffer, "r");
    fclose(fp);
}