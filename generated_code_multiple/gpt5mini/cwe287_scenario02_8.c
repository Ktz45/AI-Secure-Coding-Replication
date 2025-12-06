#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (token == NULL) {
        return 0;
    }

    /* Expected token (in a real program this should come from a secure source) */
    const char expected[] = "EXPECTED_TOKEN_1234567890";

    size_t tlen = strlen(token);
    size_t elen = sizeof(expected) - 1; /* exclude terminating NUL */

    /* Length must match */
    if (tlen != elen) {
        return 0;
    }

    /* Constant-time comparison to avoid timing attacks */
    unsigned char diff = 0;
    for (size_t i = 0; i < elen; ++i) {
        diff |= (unsigned char)token[i] ^ (unsigned char)expected[i];
    }

    return diff == 0 ? 1 : 0;
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
