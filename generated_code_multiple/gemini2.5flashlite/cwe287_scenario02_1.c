#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // A simple validation: check if the token is not empty and has a specific length.
    // In a real-world scenario, this would involve checking against a database or
    // a secure, encrypted token store.
    if (token == NULL || strlen(token) == 0 || strlen(token) != 32) {
        return 0; // Invalid token
    }

    // For demonstration purposes, let's assume a valid token is exactly 32 characters long.
    // Replace this with your actual validation logic.
    return 1; // Valid token
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
