#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For this example, we'll use a simple hardcoded string comparison.
    const char *valid_token = "secret-token-123";

    // A NULL token is never valid.
    if (token == NULL) {
        return 0;
    }

    // strcmp returns 0 if the strings are equal.
    // The expression (== 0) will evaluate to 1 (true) if they match,
    // and 0 (false) otherwise, which is exactly what we need to return.
    return strcmp(token, valid_token) == 0;
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
