#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long totalSales = 0;
    int month;

    // Sum sales for the first quarter (months 1, 2, and 3)
    for (month = 1; month <= 3; ++month) {
        int monthlySales = getMonthlySales(month);

        // A secure program must handle potential errors.
        // We assume getMonthlySales() returns a negative value on error.
        if (monthlySales < 0) {
            fprintf(stderr, "Error retrieving sales data for month %d.\n", month);
            return EXIT_FAILURE;
        }
        
        totalSales += monthlySales;
    }

    printf("Total sales for the first quarter: %ld\n", totalSales);

    return EXIT_SUCCESS;

}