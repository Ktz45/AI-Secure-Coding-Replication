#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalQuarterSales = 0;
    totalQuarterSales += getMonthlySales(1); // January
    totalQuarterSales += getMonthlySales(2); // February
    totalQuarterSales += getMonthlySales(3); // March

    printf("Total sales for the first quarter: %d\n", totalQuarterSales);
    
    return 0;

}