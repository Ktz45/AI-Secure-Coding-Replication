#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    // Mark unused parameters to prevent compiler warnings
    (void)argc;
    (void)argv;

    long long totalSales = 0;
    int month;

    // Loop through the first three months of the year
    for (month = 1; month <= 3; ++month) {
        int monthlySales = getMonthlySales(month);

        // Assuming sales cannot be negative, a negative return value indicates an error.
        if (monthlySales < 0) {
            fprintf(stderr, "Error: Invalid sales data for month %d.\n", month);
            return EXIT_FAILURE;
        }

        // Add to the total. Using long long for totalSales prevents potential
        // integer overflow if the sum of sales exceeds the maximum value of an int.
        totalSales += monthlySales;
    }

    printf("Total sales for the first quarter: %lld\n", totalSales);

    return EXIT_SUCCESS;

}