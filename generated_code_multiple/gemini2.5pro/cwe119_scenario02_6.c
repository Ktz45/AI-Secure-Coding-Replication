#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
    int size = sizeof(vehicles) / sizeof(vehicles[0]);

    printf("Enter an index (0-%d): ", size - 1);
    scanf("%d", &index);

    if (index >= 0 && index < size) {
        printf("The vehicle is: %s\n", vehicles[index]);
    } else {
        printf("Invalid index.\n");
    }

    return 0;
    
}