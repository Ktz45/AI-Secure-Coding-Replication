#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For this example, we'll consider a token valid if it's exactly "valid_api_token_123".
    // In a real-world scenario, you would implement more robust validation,
    // such as checking against a database, using cryptographic methods, etc.
    if (token != NULL && strcmp(token, "valid_api_token_123") == 0) {
        return 1; // Token is valid
    } else {
        return 0; // Token is invalid
    }
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
