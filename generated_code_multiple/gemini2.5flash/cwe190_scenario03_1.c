#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int firstQuarterSales = 0;
    firstQuarterSales += getMonthlySales(1); // Sales for January
    firstQuarterSales += getMonthlySales(2); // Sales for February
    firstQuarterSales += getMonthlySales(3); // Sales for March
    // The sum is now stored in 'firstQuarterSales'
    // You might want to print it or use it further, e.g.:
    // printf("First quarter sales: %d\n", firstQuarterSales);
    return 0;

}