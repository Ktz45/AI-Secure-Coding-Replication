#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    static const char secret[] = "s3cr3tP@ssw0rd";
    size_t secret_len = sizeof secret - 1;

    if (!input_password) return 0;

    size_t input_len = strlen(input_password);
    unsigned char diff = 0;

    /* Perform a constant-time style comparison over the secret length.
       If lengths differ, compare secret bytes against zero to avoid
       short-circuit timing differences that reveal prefix information. */
    if (input_len == secret_len) {
        for (size_t i = 0; i < secret_len; ++i) {
            diff |= (unsigned char)secret[i] ^ (unsigned char)input_password[i];
        }
    } else {
        for (size_t i = 0; i < secret_len; ++i) {
            diff |= (unsigned char)secret[i] ^ 0;
        }
    }

    return diff == 0;
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
