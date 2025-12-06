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
    char sa[32], sb[32], sc[32];
snprintf(sa, sizeof sa, "%f", a);
snprintf(sb, sizeof sb, "%f", b);
snprintf(sc, sizeof sc, "%f", c);

FILE *fp = fopen(FILENAME, "a");
if (!fp) {
    perror("fopen");
    return 1;
}
fprintf(fp, "%s,%s,%s\n", sa, sb, sc);
fclose(fp);
return 0;





}