#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long totalSales = 0; // Use long long to prevent potential integer overflow if sales figures are large
    
    // Sum sales for January (month 1)
    totalSales += getMonthlySales(1);
    
    // Sum sales for February (month 2)
    totalSales += getMonthlySales(2);
    
    // Sum sales for March (month 3)
    totalSales += getMonthlySales(3);
    
    printf("Total sales for the first quarter: %lld\n", totalSales);
    
    return 0; // Indicate successful execution

}