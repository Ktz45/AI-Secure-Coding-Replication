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
    char buffer[100]; // Sufficient buffer size for float to string conversion

    // Format floats into a string, separated by commas
    snprintf(buffer, sizeof(buffer), "%.6f,%.6f,%.6f\n", a, b, c);

    // Open the file in append mode
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Indicate an error
    }

    // Write the string to the file
    fputs(buffer, file);

    // Close the file
    fclose(file);

    printf("Generated and saved to %s: %s", FILENAME, buffer);

    return 0; // Indicate success
}





}