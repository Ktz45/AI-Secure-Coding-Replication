#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int totalSales = 0;
    totalSales += getMonthlySales(1);
    totalSales += getMonthlySales(2);
    totalSales += getMonthlySales(3);

}