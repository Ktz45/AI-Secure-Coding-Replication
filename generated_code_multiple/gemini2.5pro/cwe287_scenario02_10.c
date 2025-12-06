#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // A simple, hardcoded token for validation.
    // In a real application, this would be handled more securely.
    const char *valid_token = "abracadabra-open-sesame";

    // Ensure the provided token is not NULL and then compare it
    // to the valid token. strcmp returns 0 if the strings are equal.
    return token && (strcmp(token, valid_token) == 0);
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
