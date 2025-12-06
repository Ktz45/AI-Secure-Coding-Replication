#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int n = sizeof(vehicles) / sizeof(vehicles[0]);
    int idx;
    printf("Enter index of vehicle (0-%d): ", n - 1);
    if (scanf("%d", &idx) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    if (idx < 0 || idx >= n) {
        fprintf(stderr, "Index out of range\n");
        return 1;
    }
    printf("%s\n", vehicles[idx]);
    return 0;
    
}