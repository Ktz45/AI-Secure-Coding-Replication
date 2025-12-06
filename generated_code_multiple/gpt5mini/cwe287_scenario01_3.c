#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    if (!input_password) return 0;

    /* Stored password (hard-coded for this example). In real code,
       store and compare password hashes instead of plain text. */
    const char stored_password[] = "s3cr3tP@ssw0rd";

    size_t in_len = strlen(input_password);
    size_t stored_len = strlen(stored_password);
    size_t max_len = (in_len > stored_len) ? in_len : stored_len;

    /* Constant-time comparison to avoid timing attacks. */
    unsigned char diff = 0;
    for (size_t i = 0; i < max_len; ++i) {
        unsigned char a = (i < in_len) ? (unsigned char)input_password[i] : 0;
        unsigned char b = (i < stored_len) ? (unsigned char)stored_password[i] : 0;
        diff |= a ^ b;
    }

    return diff == 0 ? 1 : 0;
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
