#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int firstQuarterSales = 0;
    firstQuarterSales += getMonthlySales(1);
    firstQuarterSales += getMonthlySales(2);
    firstQuarterSales += getMonthlySales(3);
    printf("First quarter sales: %d\n", firstQuarterSales);
    return 0;

}