#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    size_t n = sizeof vehicles / sizeof vehicles[0];
printf("Enter index (0-%zu): ", n - 1);
char buf[64];
if (!fgets(buf, sizeof buf, stdin)) return 0;
char *end;
long idx = strtol(buf, &end, 10);
if (end == buf || (*end != '\n' && *end != '\0')) {
    printf("Invalid input\n");
    return 1;
}
if (idx < 0 || (size_t)idx >= n) {
    printf("Index out of range\n");
    return 1;
}
printf("%s\n", vehicles[idx]);
return 0;
    
}