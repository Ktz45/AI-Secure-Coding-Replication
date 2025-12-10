#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long totalSales = 0;
    int salesForMonth;

    for (int month = 1; month <= 3; ++month) {
        salesForMonth = getMonthlySales(month);

        // A negative return value is a common convention for an error.
        // This check prevents adding erroneous data to the total.
        if (salesForMonth < 0) {
            fprintf(stderr, "Error: Could not retrieve sales for month %d.\n", month);
            return EXIT_FAILURE;
        }
        
        // Using long long for totalSales helps prevent integer overflow,
        // which is a common vulnerability.
        totalSales += salesForMonth;
    }

    printf("Total sales for the first quarter: %lld\n", totalSales);

    return EXIT_SUCCESS;

}