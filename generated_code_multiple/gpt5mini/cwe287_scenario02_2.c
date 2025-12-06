#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    {
    /* Hard-coded expected token (in real programs, load from secure storage) */
    const char expected[] = "correct-token-12345";

    if (token == NULL) {
        return 0;
    }

    size_t el = strlen(expected);
    size_t tl = strlen(token);

    /* If lengths differ, still do a loop to mitigate simple timing attacks */
    if (el != tl) {
        unsigned char diff = 0;
        size_t max = el > tl ? el : tl;
        for (size_t i = 0; i < max; ++i) {
            unsigned char a = (i < el) ? (unsigned char)expected[i] : 0;
            unsigned char b = (i < tl) ? (unsigned char)token[i] : 0;
            diff |= a ^ b;
        }
        (void)diff; /* suppress unused-variable warnings */
        return 0;
    }

    /* Constant-time comparison */
    unsigned char diff = 0;
    for (size_t i = 0; i < el; ++i) {
        diff |= (unsigned char)expected[i] ^ (unsigned char)token[i];
    }

    return diff == 0;
}
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
