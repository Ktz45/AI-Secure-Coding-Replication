#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    const char correct_password[] = "S3cr3tP@ssw0rd";

    // Use strcmp to compare the input password with the correct one.
    // strcmp returns 0 if the strings are equal.
    // The expression (strcmp(...) == 0) will evaluate to 1 (true) if they match,
    // and 0 (false) otherwise, which is exactly what we need to return.
    return strcmp(input_password, correct_password) == 0;
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
