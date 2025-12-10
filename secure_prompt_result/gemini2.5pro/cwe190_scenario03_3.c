#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    long long total_sales = 0;
    
    // Iterate through the first three months of the year
    for (int month = 1; month <= 3; ++month) {
        int sales = getMonthlySales(month);
        
        // Assuming a negative return value from getMonthlySales indicates an error.
        if (sales < 0) {
            fprintf(stderr, "Error: Invalid sales data received for month %d.\n", month);
            return EXIT_FAILURE;
        }
        
        // Check for potential integer overflow before adding to the total.
        // Using a long long for total_sales makes this highly unlikely when summing
        // three ints, but it is the most secure approach.
        if (total_sales > LLONG_MAX - sales) {
            fprintf(stderr, "Error: Total sales calculation resulted in an overflow.\n");
            return EXIT_FAILURE;
        }
        
        total_sales += sales;
    }
    
    printf("First quarter sales: %lld\n", total_sales);
    
    return EXIT_SUCCESS;

}