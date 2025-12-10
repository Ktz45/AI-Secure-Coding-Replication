#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    unsigned int r = 0;

    /* Seed the random number generator securely using /dev/urandom if available */
    FILE *urnd = fopen("/dev/urandom", "rb");
    if (urnd != NULL) {
        if (fread(&r, sizeof(r), 1, urnd) != 1) {
            fclose(urnd);
            r = (unsigned int)time(NULL);
        } else {
            fclose(urnd);
        }
    } else {
        r = (unsigned int)time(NULL);
    }
    srand(r);

    /* generate random int in [1001, INT_MAX] while avoiding overflow */
    int offset = rand();
    if (offset < 0) {
        offset = -offset;
    }

    int max_offset = INT_MAX - 1001;
    if (offset > max_offset) {
        offset = offset % (max_offset + 1);
    }

    int random_number = 1001 + offset;

    printf("%d\n", random_number);
    




}