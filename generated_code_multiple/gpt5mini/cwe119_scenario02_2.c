#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    size_t count = sizeof(vehicles) / sizeof(vehicles[0]);
char line[100];
char *endptr;
long idx;

printf("Enter vehicle index (0-%zu): ", count ? count - 1 : 0);
if (!fgets(line, sizeof line, stdin)) {
    fprintf(stderr, "No input\n");
    return 1;
}

idx = strtol(line, &endptr, 10);
if (endptr == line || (*endptr != '\n' && *endptr != '\0')) {
    fprintf(stderr, "Invalid number\n");
    return 1;
}

if (idx < 0 || idx >= (long)count) {
    fprintf(stderr, "Index out of range\n");
    return 1;
}

printf("%s\n", vehicles[idx]);
return 0;
    
}