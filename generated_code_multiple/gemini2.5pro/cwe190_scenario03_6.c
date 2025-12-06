#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int total_sales = 0;
    for (int month = 1; month <= 3; month++) {
        total_sales += getMonthlySales(month);
    }
    printf("Sales for the first quarter: %d\n", total_sales);

}