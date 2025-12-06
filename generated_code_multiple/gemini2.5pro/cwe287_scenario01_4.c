#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    // The "correct" password stored in the system.
    // In a real application, this should be a securely stored hash, not a plaintext string.
    const char *correct_password = "s3cr3t_p4ssw0rd";

    // Use strcmp to compare the input password with the correct one.
    // strcmp returns 0 if the two strings are identical.
    if (strcmp(input_password, correct_password) == 0) {
        return 1; // Authenticated
    }

    return 0; // Not authenticated
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
