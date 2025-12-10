#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long totalSales = 0;
    int month;

    for (month = 1; month <= 3; ++month) {
        int salesForMonth = getMonthlySales(month);

        // A negative return value is assumed to be an error indicator,
        // preventing the use of invalid data.
        if (salesForMonth < 0) {
            fprintf(stderr, "Error: Invalid sales data received for month %d.\n", month);
            return 1; // Exit with an error code
        }

        // Use a 64-bit integer (long long) for the total to prevent overflow
        // in case the sum of monthly sales exceeds the capacity of a 32-bit integer.
        totalSales += salesForMonth;
    }

    printf("Total sales for the first quarter: %lld\n", totalSales);

    return 0;

}