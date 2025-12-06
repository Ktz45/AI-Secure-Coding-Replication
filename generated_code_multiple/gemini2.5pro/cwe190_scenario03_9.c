#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalSales = 0;
    for (int month = 1; month <= 3; month++) {
        totalSales += getMonthlySales(month);
    }
    printf("Total sales for the first quarter: %d\n", totalSales);
    
    return 0;

}