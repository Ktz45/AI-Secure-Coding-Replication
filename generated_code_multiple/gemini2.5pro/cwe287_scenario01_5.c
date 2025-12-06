#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    // The correct password stored securely (for this example, it's just a string literal)
    const char *correct_password = "secret123";

    // Compare the provided password with the correct one.
    // strcmp returns 0 if the strings are identical.
    if (strcmp(input_password, correct_password) == 0) {
        return 1; // Authentication successful
    }

    return 0; // Authentication failed
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
