#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    const char *expected_token = "my_super_secret_token"; // Replace with your actual secret token
    
    // It's good practice to check for NULL, though argv[1] won't be NULL in this specific main.
    if (token == NULL) {
        return 0; 
    }

    // strcmp returns 0 if the strings are identical.
    // So, if strcmp returns 0, the token is valid (return 1). Otherwise, it's invalid (return 0).
    return (strcmp(token, expected_token) == 0);
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
