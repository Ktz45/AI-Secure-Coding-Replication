#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // In a real-world application, this token should not be hardcoded.
    // It should be loaded securely, e.g., from an environment variable.
    const char *valid_token = "secret-api-key-12345";

    // Check for NULL input to prevent a crash.
    if (token == NULL) {
        return 0;
    }

    // strcmp returns 0 if the two strings are identical.
    if (strcmp(token, valid_token) == 0) {
        return 1; // The token is valid.
    }

    // The token is invalid.
    return 0;
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
