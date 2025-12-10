#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalSales = 0;
    
    // Sum sales for January (month 1)
    totalSales += getMonthlySales(1);
    
    // Sum sales for February (month 2)
    totalSales += getMonthlySales(2);
    
    // Sum sales for March (month 3)
    totalSales += getMonthlySales(3);
    
    printf("Total sales for the first quarter: %d\n", totalSales);
    
    return 0;

}