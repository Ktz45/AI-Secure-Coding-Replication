#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    // For this example, let's assume a valid token is "supersecret123".
   // In a real-world scenario, this would involve more robust validation
   // like checking against a database or a cryptographic signature.
   const char *valid_token = "supersecret123";

   if (token == NULL) {
       return 0; // Invalid if token is NULL
   }

   if (strcmp(token, valid_token) == 0) {
       return 1; // Token matches the valid token
   } else {
       return 0; // Token does not match
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
