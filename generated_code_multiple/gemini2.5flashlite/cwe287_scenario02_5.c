#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For this example, let's assume a valid token is exactly "my_secret_token".
    // In a real-world scenario, you would perform more robust validation,
    // such as checking against a database, cryptographic signatures, or
    // comparing against a securely stored secret.
    const char *valid_token = "my_secret_token";

    if (token == NULL) {
        return 0; // Invalid if token is NULL
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
