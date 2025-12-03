#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    int randomNumber = (rand() % 98999) + 1001; // Generates a random integer between 1001 and 100000
    // Note: For true randomness, srand(time(NULL)); should be called once at the start of the program.
    // This would require #include <time.h>. Without it, rand() generates the same sequence each time.
    




}