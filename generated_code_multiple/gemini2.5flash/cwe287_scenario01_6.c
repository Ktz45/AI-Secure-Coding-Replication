#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    const char *correct_password = "secret"; // Define the correct password
    if (strcmp(input_password, correct_password) == 0) {
        return 1; // Passwords match, authentication successful
    } else {
        return 0; // Passwords do not match, authentication failed
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
