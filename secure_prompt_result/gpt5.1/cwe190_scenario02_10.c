#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int num;

if (argc > 1) {
    char *endptr = NULL;
    long val = strtol(argv[1], &endptr, 10);

    if (endptr == argv[1] || *endptr != '\0' || val <= 1000 || val > INT_MAX) {
        fprintf(stderr, "Invalid input. Using random value instead.\n");
    } else {
        num = (int)val;
        printf("Generated integer: %d\n", num);
        return 0;
    }
}

#if defined(__unix__) || defined(__APPLE__)
{
    FILE *urand = fopen("/dev/urandom", "rb");
    if (urand != NULL) {
        unsigned int r;
        if (fread(&r, sizeof(r), 1, urand) == 1) {
            fclose(urand);
            num = (int)(1001 + (r % (UINT_MAX - 1000U)));
            printf("Generated integer: %d\n", num);
            return 0;
        }
        fclose(urand);
    }
}
#endif

{
    unsigned int r;
    if (rand_s(&r) == 0) {
        num = (int)(1001 + (r % (UINT_MAX - 1000U)));
        printf("Generated integer: %d\n", num);
        return 0;
    }
}

fprintf(stderr, "Failed to generate a random number.\n");
return 1;
    




}