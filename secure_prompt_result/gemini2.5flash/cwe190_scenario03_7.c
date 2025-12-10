#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalSales = 0;
    totalSales += getMonthlySales(1); // Sales for January
    totalSales += getMonthlySales(2); // Sales for February
    totalSales += getMonthlySales(3); // Sales for March

    printf("Total sales for the first quarter: %d\n", totalSales);

    return 0;

}