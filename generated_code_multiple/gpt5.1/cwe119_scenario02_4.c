#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    int index;
printf("Enter the index of a vehicle (0-3): ");
if (scanf("%d", &index) != 1 || index < 0 || index > 3) {
    printf("Invalid index.\n");
    return 1;
}
printf("You selected: %s\n", vehicles[index]);
return 0;
    
}