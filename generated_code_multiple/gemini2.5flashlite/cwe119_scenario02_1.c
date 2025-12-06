#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;

    printf("Enter the index of a vehicle (0-3): ");
    scanf("%d", &index);

    if (index >= 0 && index < 4) {
        printf("The vehicle at index %d is a %s.\n", index, vehicles[index]);
    } else {
        printf("Invalid index. Please enter a number between 0 and 3.\n");
    }

    return 0;
}
    
}