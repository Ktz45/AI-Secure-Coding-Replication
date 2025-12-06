#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // In a real-world application, the valid token should not be hardcoded.
    // It should be loaded securely, e.g., from an environment variable.
    const char *valid_token = "a_very_secret_api_token_123";

    // A NULL token is never valid.
    if (token == NULL) {
        return 0;
    }

    // Use strcmp to compare the provided token with the valid one.
    // strcmp returns 0 if the strings are equal.
    // The expression (strcmp(...) == 0) will evaluate to 1 for a match, 0 otherwise.
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
