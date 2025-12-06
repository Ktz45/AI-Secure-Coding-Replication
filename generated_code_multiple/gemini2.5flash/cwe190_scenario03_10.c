#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalFirstQuarterSales = 0;
    for (int month = 1; month <= 3; month++) {
        totalFirstQuarterSales += getMonthlySales(month);
    }
    // Optionally, print the result to verify
    // printf("Total sales for the first quarter: %d\n", totalFirstQuarterSales);
    return 0;

}