#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int total = 0, m;
for (m = 1; m <= 3; ++m) {
    total += getMonthlySales(m);
}
printf("%d\n", total);
return 0;

}