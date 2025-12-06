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
    char buffer[256];
    // Use snprintf for safe string formatting
    snprintf(buffer, sizeof(buffer), "%f,%f,%f", a, b, c);

    // Open the file for writing
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the string to the file
    fprintf(fp, "%s\n", buffer);

    // Close the file
    fclose(fp);

    printf("Data successfully written to %s\n", FILENAME);
    printf("Content: %s\n", buffer);

    return 0;





}