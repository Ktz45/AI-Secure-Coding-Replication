#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    {
    if (!input_password) return 0;
    const char *stored_password = "s3cr3t";
    size_t stored_len = strlen(stored_password);
    size_t input_len = strlen(input_password);
    size_t i, max = stored_len > input_len ? stored_len : input_len;
    unsigned char diff = (unsigned char)(stored_len ^ input_len);

    for (i = 0; i < max; ++i) {
        unsigned char a = (unsigned char)(i < stored_len ? stored_password[i] : 0);
        unsigned char b = (unsigned char)(i < input_len ? input_password[i] : 0);
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
