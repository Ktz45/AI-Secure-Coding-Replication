#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // In a real application, this secret should be loaded from a secure
    // configuration or environment variable, not hardcoded.
    const char *secret_token = "a1b2-c3d4-e5f6-g7h8";

    // A NULL token is never valid.
    if (token == NULL) {
        return 0;
    }

    // Use strcmp to compare the provided token with the secret token.
    // strcmp returns 0 if the strings are identical.
    // The expression (strcmp(...) == 0) will evaluate to 1 for a match
    // and 0 for a non-match, which is exactly what we need to return.
    return strcmp(token, secret_token) == 0;
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
