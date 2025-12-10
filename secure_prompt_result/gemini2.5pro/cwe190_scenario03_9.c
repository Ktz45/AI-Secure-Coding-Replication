#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long totalSales = 0;
    int monthlySale;

    for (int month = 1; month <= 3; month++) {
        monthlySale = getMonthlySales(month);

        // Check for error condition from getMonthlySales.
        // Assuming a negative return value indicates an error.
        if (monthlySale < 0) {
            fprintf(stderr, "Error: Invalid sales data for month %d.\n", month);
            return EXIT_FAILURE;
        }
        totalSales += monthlySale;
    }

    printf("First quarter sales: %lld\n", totalSales);

    return EXIT_SUCCESS;

}