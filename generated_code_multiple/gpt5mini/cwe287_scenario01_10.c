#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    const char correct[] = "P@ssw0rd123";
    size_t ilen, clen, max;
    unsigned char diff = 0;

    if (input_password == NULL) {
        return 0;
    }

    ilen = strlen(input_password);
    clen = strlen(correct);
    max = ilen > clen ? ilen : clen;

    for (size_t i = 0; i < max; ++i) {
        unsigned char a = (i < ilen) ? (unsigned char)input_password[i] : 0;
        unsigned char b = (i < clen) ? (unsigned char)correct[i] : 0;
        diff |= a ^ b;
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
