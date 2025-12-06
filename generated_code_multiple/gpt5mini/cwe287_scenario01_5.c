#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    const char stored[] = "s3cr3tP@ss";
    if (input_password == NULL) return 0;

    size_t inlen = strlen(input_password);
    size_t slen = strlen(stored);
    size_t max = inlen > slen ? inlen : slen;
    unsigned char diff = 0;

    /* Constant-time comparison to avoid leaking timing information */
    for (size_t i = 0; i < max; i++) {
        unsigned char a = (i < inlen) ? (unsigned char)input_password[i] : 0;
        unsigned char b = (i < slen) ? (unsigned char)stored[i] : 0;
        diff |= a ^ b;
    }

    return diff == 0 ? 1 : 0;
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
