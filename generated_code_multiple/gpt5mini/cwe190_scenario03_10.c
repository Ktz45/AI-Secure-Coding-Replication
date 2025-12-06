#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    int sum = 0;
int m;
for (m = 1; m <= 3; m++) {
    sum += getMonthlySales(m);
}
printf("%d\n", sum);
return 0;

}