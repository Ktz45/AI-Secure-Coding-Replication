#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    const char *valid_api_token = "your_secret_api_token_here"; // Replace with the actual valid token

    if (token == NULL) {
        return 0; // Invalid if token is NULL
    }

    if (strcmp(token, valid_api_token) == 0) {
        return 1; // Token is valid
    } else {
        return 0; // Token is invalid
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
