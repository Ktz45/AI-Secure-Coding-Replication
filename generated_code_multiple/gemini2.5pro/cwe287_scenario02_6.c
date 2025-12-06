#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // In a real application, this would be a more sophisticated check,
    // and the secret would not be hardcoded.
    const char *valid_token = "a1b2-c3d4-e5f6-g7h8";

    // A NULL token is invalid.
    if (token == NULL) {
        return 0;
    }

    // Compare the provided token with the valid one.
    // strcmp returns 0 if the strings are identical.
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
