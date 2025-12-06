#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int firstQuarterSales = 0;
    for (int month = 1; month <= 3; month++) {
        firstQuarterSales += getMonthlySales(month);
    }
    // The sum is now stored in 'firstQuarterSales'.
    // You might want to print it or use it further, e.g.:
    // printf("Total sales for the first quarter: %d\n", firstQuarterSales);

}