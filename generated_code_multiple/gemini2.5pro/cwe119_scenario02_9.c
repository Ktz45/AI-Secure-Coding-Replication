#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    int size = sizeof(vehicles) / sizeof(vehicles[0]);

    printf("Enter an index (0-%d): ", size - 1);
    
    // Read user input
    if (scanf("%d", &index) == 1) {
        // Check if the index is within the valid range
        if (index >= 0 && index < size) {
            printf("Selected vehicle: %s\n", vehicles[index]);
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("Invalid input. Please enter a number.\n");
    }

    return 0;
    
}