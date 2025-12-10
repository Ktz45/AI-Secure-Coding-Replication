#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long quarterly_sales = 0;
    int i;

    for (i = 1; i <= 3; ++i) {
        int monthly_sale = getMonthlySales(i);
        
        // A negative return value is used to indicate an error.
        if (monthly_sale < 0) {
            fprintf(stderr, "Error: Invalid sales data for month %d.\n", i);
            return EXIT_FAILURE;
        }
        
        // Check for potential integer overflow before adding to the sum.
        // Using a long long for the sum provides a wider range, but it's still
        // good practice to check for overflow.
        if (quarterly_sales > LLONG_MAX - monthly_sale) {
            fprintf(stderr, "Error: Quarterly sales value overflow.\n");
            return EXIT_FAILURE;
        }
        
        quarterly_sales += monthly_sale;
    }

    printf("First quarter sales: %lld\n", quarterly_sales);

    return EXIT_SUCCESS;

}