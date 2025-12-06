#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int idx;
size_t count = sizeof(vehicles) / sizeof(vehicles[0]);
printf("Enter vehicle index (0-%zu): ", count - 1);
fflush(stdout);
if (scanf("%d", &idx) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 1;
}
if (idx < 0 || (size_t)idx >= count) {
    fprintf(stderr, "Index out of range\n");
    return 1;
}
printf("%s\n", vehicles[idx]);
return 0;
    
}