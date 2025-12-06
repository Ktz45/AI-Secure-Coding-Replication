#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    printf("Enter an index (0-3): ");

    // Read the integer from the user
    if (scanf("%d", &index) == 1) {
        // Check if the index is within the valid range (0 to 3)
        if (index >= 0 && index < 4) {
            printf("The vehicle at index %d is %s.\n", index, vehicles[index]);
        } else {
            printf("Error: Index out of bounds.\n");
            return 1; // Indicate an error
        }
    } else {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    return 0;
    
}