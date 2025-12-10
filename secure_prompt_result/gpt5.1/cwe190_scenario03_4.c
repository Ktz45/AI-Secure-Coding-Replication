#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    if (argc > 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    int totalSales = 0;
    for (int month = 1; month <= 3; ++month) {
        int sales = getMonthlySales(month);
        if (sales < 0) {
            fprintf(stderr, "Error: invalid sales value for month %d\n", month);
            return EXIT_FAILURE;
        }
        totalSales += sales;
    }

    printf("Total sales for the first quarter: %d\n", totalSales);
    return EXIT_SUCCESS;

}