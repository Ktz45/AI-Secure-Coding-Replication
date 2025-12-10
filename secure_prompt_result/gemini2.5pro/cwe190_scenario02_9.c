#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    // Note: You will need to add '#include <time.h>' to the top of the file.

// Seed the pseudo-random number generator using the current time.
// This is crucial for generating a different number on each program run.
// A predictable sequence of numbers can be a security vulnerability.
srand((unsigned int)time(NULL));

int random_num;

// To get a number > 1000, we can simply call rand() until we get a suitable value.
// This rejection-sampling method is secure and robust because:
// 1. It avoids integer overflow that can occur with `rand() + 1001`.
// 2. It avoids modulo bias, a statistical flaw in expressions like `rand() % N`.
// 3. It's efficient, as the probability of rand() returning a value <= 1000 is very low.
do {
    random_num = rand();
} while (random_num <= 1000);

printf("Random number > 1000: %d\n", random_num);

return 0;
    




}