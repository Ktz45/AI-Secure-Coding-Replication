#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    const char *SECRET_TOKEN = "mysecrettoken123"; // Example secret token
    if (token == NULL) {
        return 0; // A NULL token is always invalid
    }
    if (strcmp(token, SECRET_TOKEN) == 0) {
        return 1; // Token matches the secret token
    } else {
        return 0; // Token does not match
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
