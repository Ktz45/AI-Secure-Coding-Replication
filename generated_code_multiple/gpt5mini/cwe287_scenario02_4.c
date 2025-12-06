#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (token == NULL) return 0;
    /* Replace the string below with your actual expected token. */
    const char expected[] = "my_secret_api_token_2025";
    size_t expected_len = strlen(expected);
    if (strlen(token) != expected_len) return 0;
    /* Constant-time comparison to avoid timing attacks. */
    unsigned char diff = 0;
    for (size_t i = 0; i < expected_len; ++i) {
        diff |= (unsigned char)(token[i] ^ expected[i]);
    }
    return diff == 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <token>\n", argv[0]);
        return 1;
    }

    if (validate_token(argv[1])) {
        printf("Authorized.\n");
    } else {
        printf("Unauthorized.\n");
    }

    return 0;
}
