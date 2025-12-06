#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // In a real application, this would involve a more secure check,
    // e.g., against a database or using cryptographic methods.
    // For this example, we'll use a simple hardcoded string comparison.
    const char *valid_token = "secret-token-12345";

    // A robust implementation should handle NULL pointers.
    if (token == NULL) {
        return 0;
    }

    // strcmp returns 0 if the strings are equal.
    if (strcmp(token, valid_token) == 0) {
        return 1; // Token is valid
    }

    return 0; // Token is invalid
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
