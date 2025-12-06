#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int quarterlySales = 0;
    for (int month = 1; month <= 3; month++) {
        quarterlySales += getMonthlySales(month);
    }
    printf("First quarter sales: %d\n", quarterlySales);
    return 0;

}