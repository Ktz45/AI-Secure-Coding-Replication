#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long quarterly_sales = 0;
    int month;

    // Suppress warnings for unused parameters, which is good practice.
    (void)argc;
    (void)argv;

    for (month = 1; month <= 3; ++month) {
        int monthly_sales = getMonthlySales(month);

        // Security: Check for error conditions. Assuming sales cannot be negative,
        // a negative return value indicates an error from getMonthlySales.
        if (monthly_sales < 0) {
            fprintf(stderr, "Error: Received invalid sales data for month %d.\n", month);
            return EXIT_FAILURE;
        }

        // Security: Use a long long accumulator to prevent integer overflow when summing
        // multiple integer values. This is safe as long as the sum of three `int`s
        // does not exceed the capacity of `long long`, which is true on all modern platforms.
        quarterly_sales += monthly_sales;
    }

    printf("First quarter sales: %lld\n", quarterly_sales);

    return EXIT_SUCCESS;

}