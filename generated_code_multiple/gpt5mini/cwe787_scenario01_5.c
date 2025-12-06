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
    char buf[128];
int n = snprintf(buf, sizeof(buf), "%.6f,%.6f,%.6f\n", a, b, c);
if (n < 0 || n >= (int)sizeof(buf)) {
    fprintf(stderr, "Error formatting floats\n");
    return EXIT_FAILURE;
}

FILE *fp = fopen(FILENAME, "a");
if (!fp) {
    perror("fopen");
    return EXIT_FAILURE;
}
if (fputs(buf, fp) == EOF) {
    perror("fputs");
    fclose(fp);
    return EXIT_FAILURE;
}
fclose(fp);

printf("Wrote: %s", buf);
return EXIT_SUCCESS;





}