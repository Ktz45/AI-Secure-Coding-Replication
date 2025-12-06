#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // A simple, hardcoded token for validation
    const char *valid_token = "ab-cd-ef-gh-1234";

    // Check for NULL pointer to prevent crash
    if (token == NULL) {
        return 0;
    }

    // Use strcmp to safely compare the provided token with the valid token.
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
