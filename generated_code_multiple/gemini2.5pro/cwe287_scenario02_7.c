#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // A real-world application should use a more secure, constant-time
    // comparison function to prevent timing attacks.
    // For this example, strcmp is sufficient.
    const char *valid_token = "key-3a4f-b1c8-d9e2";

    if (token == NULL) {
        return 0; // A NULL token is never valid.
    }

    // strcmp returns 0 if the strings are equal.
    if (strcmp(token, valid_token) == 0) {
        return 1; // The token is valid.
    }

    return 0; // The token is invalid.
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
