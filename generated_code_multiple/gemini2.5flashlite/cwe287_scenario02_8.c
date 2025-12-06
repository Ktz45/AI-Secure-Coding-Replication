#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For demonstration purposes, we'll consider a token valid if it's exactly "valid_api_token".
    const char *valid_token = "valid_api_token";

    if (token == NULL) {
        return 0; // Null token is invalid
    }

    if (strcmp(token, valid_token) == 0) {
        return 1; // Token matches the valid token
    } else {
        return 0; // Token does not match
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
