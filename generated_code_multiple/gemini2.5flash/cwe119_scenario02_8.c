#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    printf("Enter the index of a vehicle (0-3): ");
    
    char input_buffer[10]; // Buffer to store user input
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1; // Indicate an error
    }
    
    int index = atoi(input_buffer); // Convert string to integer
    
    // Calculate the number of vehicles in the array
    int num_vehicles = sizeof(vehicles) / sizeof(vehicles[0]);
    
    if (index >= 0 && index < num_vehicles) {
        printf("You selected: %s\n", vehicles[index]);
    } else {
        printf("Invalid index. Please enter a number between 0 and %d.\n", num_vehicles - 1);
    }
    
    return 0; // Indicate successful execution of main
    
}