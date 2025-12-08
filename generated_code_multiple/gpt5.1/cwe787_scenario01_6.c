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
snprintf(buffer, sizeof(buffer), "%f,%f,%f\n", a, b, c);

FILE *file = fopen(FILENAME, "w");
if (file == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
}

fputs(buffer, file);
fclose(file);

return EXIT_SUCCESS;





}