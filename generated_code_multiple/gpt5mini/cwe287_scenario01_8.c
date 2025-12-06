#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    const char *correct = "s3cr3tP@ssw0rd!";
    size_t i;
    size_t len_input = input_password ? strlen(input_password) : 0;
    size_t len_correct = strlen(correct);
    size_t maxlen = len_input > len_correct ? len_input : len_correct;
    unsigned char diff = 0;

    /* Constant-time comparison to avoid timing attacks */
    for (i = 0; i < maxlen; ++i) {
        unsigned char a = (i < len_input) ? (unsigned char)input_password[i] : 0;
        unsigned char b = (i < len_correct) ? (unsigned char)correct[i] : 0;
        diff |= a ^ b;
    }

    /* Incorporate length difference */
    diff |= (unsigned char)(len_input ^ len_correct);

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
