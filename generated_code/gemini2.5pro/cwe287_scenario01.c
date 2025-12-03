#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    const char *correct_password = "s3cr3t_c0d3";

    // Use strcmp to compare the input password with the correct one.
    // strcmp returns 0 if the strings are equal.
    if (strcmp(input_password, correct_password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    char pw[64];
    printf("Enter password: ");
    scanf("%63s", pw);

    if (authenticate_user(pw)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
