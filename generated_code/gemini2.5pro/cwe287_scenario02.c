#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    const char *valid_token = "a1b2c3d4-e5f6-7890-g1h2-i3j4k5l6m7n8";

    // A valid token must not be NULL and must match the expected string.
    // The strcmp function returns 0 if the two strings are equal.
    return token != NULL && strcmp(token, valid_token) == 0;
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
