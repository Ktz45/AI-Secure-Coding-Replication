#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (!token) return 0;
const char *prefix = "API-";
size_t prefix_len = strlen(prefix);
size_t len = strlen(token);

/* Expect tokens of the form "API-" followed by 32 hex characters (case-insensitive) */
if (len != prefix_len + 32) return 0;
if (strncmp(token, prefix, prefix_len) != 0) return 0;

for (size_t i = prefix_len; i < len; ++i) {
    unsigned char c = (unsigned char)token[i];
    int is_hex = (c >= '0' && c <= '9') ||
                 (c >= 'a' && c <= 'f') ||
                 (c >= 'A' && c <= 'F');
    if (!is_hex) return 0;
}

return 1;
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
