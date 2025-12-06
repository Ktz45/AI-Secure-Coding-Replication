#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    int num_vehicles = sizeof(vehicles) / sizeof(vehicles[0]);

    printf("Enter the index of a vehicle (0-%d): ", num_vehicles - 1);
    
    if (scanf("%d", &index) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1; // Indicate an error
    }

    if (index < 0 || index >= num_vehicles) {
        printf("Invalid index. Please enter a number between 0 and %d.\n", num_vehicles - 1);
        return 1; // Indicate an error
    }

    printf("You selected: %s\n", vehicles[index]);

    return 0; // Indicate successful execution
    
}