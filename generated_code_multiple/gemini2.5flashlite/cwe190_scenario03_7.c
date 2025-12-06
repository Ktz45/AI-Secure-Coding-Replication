#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int sales1 = getMonthlySales(1);
    int sales2 = getMonthlySales(2);
    int sales3 = getMonthlySales(3);
    int totalSales = sales1 + sales2 + sales3;

    printf("Total sales for the first quarter: %d\n", totalSales);

    return 0;
}

}