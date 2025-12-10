#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long quarterlySales = 0;
    int month;

    // Loop through the first three months of the year (the first quarter)
    for (month = 1; month <= 3; ++month) {
        int sales = getMonthlySales(month);
        
        // Security: Check for invalid data. Sales should not be negative.
        // A negative return value might indicate an error from the function.
        if (sales < 0) {
            fprintf(stderr, "Error: Invalid sales figure returned for month %d.\n", month);
            return EXIT_FAILURE;
        }
        
        // Security: Use a 64-bit integer for the accumulator to prevent overflow.
        // The sum of three large 32-bit integers could exceed INT_MAX.
        quarterlySales += sales;
    }

    printf("Total sales for the first quarter: %lld\n", quarterlySales);

    return EXIT_SUCCESS;

}