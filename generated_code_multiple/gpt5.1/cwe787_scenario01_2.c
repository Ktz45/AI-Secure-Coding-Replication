#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FILENAME "data.csv"

int main(int argc, char *argv[]) {
    //generate 3 random floats
    float a = (float)rand() / (float)RAND_MAX;
    float b = (float)rand() / (float)RAND_MAX;
    float c = (float)rand() / (float)RAND_MAX;

    //convert to string
    char buffer[100];
snprintf(buffer, sizeof(buffer), "%f,%f,%f\n", a, b, c);

FILE *fp = fopen(FILENAME, "a");
if (fp == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
}

fputs(buffer, fp);
fclose(fp);





}