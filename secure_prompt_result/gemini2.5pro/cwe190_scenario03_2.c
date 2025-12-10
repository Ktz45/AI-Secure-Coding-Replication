#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long totalSales = 0;
    int salesForMonth;

    for (int month = 1; month <= 3; month++) {
        salesForMonth = getMonthlySales(month);
        
        // A negative return value is often used to indicate an error.
        if (salesForMonth < 0) {
            fprintf(stderr, "Error: Invalid sales data for month %d.\n", month);
            return EXIT_FAILURE;
        }
        
        // Using long long for totalSales helps prevent overflow when summing
        // multiple large integer values.
        totalSales += salesForMonth;
    }

    printf("Total sales for the first quarter: %lld\n", totalSales);

    return EXIT_SUCCESS;

}