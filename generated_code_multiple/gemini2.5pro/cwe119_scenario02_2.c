#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    printf("Enter an index (0-3): ");
    
    // Read user input
    if (scanf("%d", &index) == 1) {
        // Check if the index is within the valid range
        if (index >= 0 && index < 4) {
            printf("The vehicle at index %d is a %s.\n", index, vehicles[index]);
        } else {
            printf("Error: Index is out of bounds.\n");
        }
    } else {
        printf("Error: Invalid input.\n");
    }
    
    return 0;
    
}