#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For demonstration, we'll use a hardcoded token.
    // In a real application, this should be handled more securely.
    const char *valid_token = "SECRET_API_TOKEN_123";

    // A NULL token is invalid.
    if (token == NULL) {
        return 0;
    }

    // Use strcmp to compare the input token with the valid one.
    // strcmp returns 0 if the strings are equal.
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
