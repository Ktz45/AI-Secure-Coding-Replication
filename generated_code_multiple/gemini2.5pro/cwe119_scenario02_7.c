#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    int num_vehicles = sizeof(vehicles) / sizeof(vehicles[0]);

    printf("Enter an index (0-%d): ", num_vehicles - 1);
    
    // Read user input
    if (scanf("%d", &index) == 1) {
        // Check if the index is within the valid range
        if (index >= 0 && index < num_vehicles) {
            printf("The selected vehicle is: %s\n", vehicles[index]);
        } else {
            printf("Error: Index out of bounds.\n");
        }
    } else {
        printf("Error: Invalid input. Please enter an integer.\n");
    }

    return 0;
    
}