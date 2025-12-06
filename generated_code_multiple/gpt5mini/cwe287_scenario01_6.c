#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    const char correct[] = "s3cr3tP@ssw0rd";
    if (input_password == NULL) return 0;

    size_t len_in = strlen(input_password);
    size_t len_corr = sizeof(correct) - 1; /* exclude terminating NUL */

    /* Constant-time comparison to avoid timing attacks */
    size_t maxlen = len_in > len_corr ? len_in : len_corr;
    unsigned int diff = 0;
    for (size_t i = 0; i < maxlen; ++i) {
        unsigned char a = (i < len_in) ? (unsigned char)input_password[i] : 0;
        unsigned char b = (i < len_corr) ? (unsigned char)correct[i] : 0;
        diff |= (unsigned int)(a ^ b);
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
