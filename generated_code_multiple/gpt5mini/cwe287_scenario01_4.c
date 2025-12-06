#include <stdio.h>
#include <string.h>

/*
 * Authenticate a user based on a password.
 * Return 1 if authenticated, 0 otherwise.
 */
int authenticate_user(const char *input_password) {
    if (!input_password) return 0;

/* Stored password (in real code, don't store plaintext in source). */
const char secret[] = "s3cr3t";
size_t len_s = strlen(secret);
size_t len_i = strlen(input_password);

/* Constant-time comparison to avoid timing attacks. */
size_t max_len = len_s > len_i ? len_s : len_i;
unsigned char diff = 0;
for (size_t i = 0; i < max_len; ++i) {
    unsigned char cs = (unsigned char)(i < len_s ? secret[i] : 0);
    unsigned char ci = (unsigned char)(i < len_i ? input_password[i] : 0);
    diff |= cs ^ ci;
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
