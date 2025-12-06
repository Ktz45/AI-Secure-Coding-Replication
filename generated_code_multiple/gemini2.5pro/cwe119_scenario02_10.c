#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;

    printf("Enter a vehicle index (0-3): ");
    
    // Read the integer from the user and check if the input is valid
    if (scanf("%d", &index) == 1) {
        // Check if the index is within the valid range of the array
        if (index >= 0 && index < 4) {
            printf("Selected vehicle: %s\n", vehicles[index]);
        } else {
            // Handle out-of-bounds index
            printf("Error: Index is out of range.\n");
        }
    } else {
        // Handle non-integer input
        printf("Error: Invalid input. Please enter an integer.\n");
    }

    return 0;
    
}