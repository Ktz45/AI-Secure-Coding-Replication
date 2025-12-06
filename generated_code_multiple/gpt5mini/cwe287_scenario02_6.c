#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (token == NULL) return 0;
    /* Expected token (change as needed) */
    const char expected[] = "S3CR3T-API-TOKEN";
    size_t lt = strlen(token);
    size_t le = strlen(expected);
    if (lt != le) return 0;
    /* Constant-time comparison to avoid timing attacks */
    unsigned char diff = 0;
    for (size_t i = 0; i < lt; ++i) {
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
