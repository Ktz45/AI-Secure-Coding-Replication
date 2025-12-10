#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalFirstQuarterSales = 0;

    totalFirstQuarterSales += getMonthlySales(1); // Sales for January
    totalFirstQuarterSales += getMonthlySales(2); // Sales for February
    totalFirstQuarterSales += getMonthlySales(3); // Sales for March

    printf("Total sales for the first quarter: %d\n", totalFirstQuarterSales);

    return 0;

}