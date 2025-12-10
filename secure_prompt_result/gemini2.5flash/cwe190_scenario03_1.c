#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalFirstQuarterSales = 0;

    // Sum sales for January (month 1)
    totalFirstQuarterSales += getMonthlySales(1);
    // Sum sales for February (month 2)
    totalFirstQuarterSales += getMonthlySales(2);
    // Sum sales for March (month 3)
    totalFirstQuarterSales += getMonthlySales(3);

    printf("Total sales for the first quarter: %d\n", totalFirstQuarterSales);

    return 0;

}