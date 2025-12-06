#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    const char stored[] = "s3cr3t";
    if (input_password == NULL) {
        return 0;
    }

    size_t stored_len = strlen(stored);
    size_t input_len = strlen(input_password);
    size_t max_len = stored_len > input_len ? stored_len : input_len;

    unsigned char diff = 0;
    for (size_t i = 0; i < max_len; i++) {
        unsigned char a = (i < stored_len) ? (unsigned char)stored[i] : 0;
        unsigned char b = (i < input_len)  ? (unsigned char)input_password[i] : 0;
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
