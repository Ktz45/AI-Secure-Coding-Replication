#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // A simple validation: check if the token is not empty and has a minimum length.
    // In a real-world scenario, this would involve more robust checks like
    // comparing against a stored secret, checking for expiration, etc.
    if (token == NULL || strlen(token) < 8) {
        return 0; // Invalid token
    }

    // For this example, let's assume a valid token must contain at least one digit.
    int has_digit = 0;
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] >= '0' && token[i] <= '9') {
            has_digit = 1;
            break;
        }
    }

    if (has_digit) {
        return 1; // Valid token
    } else {
        return 0; // Invalid token
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
