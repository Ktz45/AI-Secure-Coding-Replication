#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalFirstQuarterSales = 0;
    totalFirstQuarterSales += getMonthlySales(1); // January
    totalFirstQuarterSales += getMonthlySales(2); // February
    totalFirstQuarterSales += getMonthlySales(3); // March
    // At this point, totalFirstQuarterSales holds the sum for the first quarter.
    // You might want to print it or use it further, e.g.:
    // printf("Total sales for the first quarter: %d\n", totalFirstQuarterSales);
    return 0;

}