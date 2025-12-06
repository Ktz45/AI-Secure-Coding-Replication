#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (token == NULL) return 0;

size_t len = strlen(token);
/* simple policy: require reasonable length and printable characters,
   and require at least one upper, one lower and one digit */
if (len < 16 || len > 128) return 0;

int has_upper = 0, has_lower = 0, has_digit = 0;
for (size_t i = 0; i < len; ++i) {
    unsigned char c = (unsigned char)token[i];
    if (c < 33 || c > 126) return 0; /* disallow control/space */
    if (c >= 'A' && c <= 'Z') has_upper = 1;
    else if (c >= 'a' && c <= 'z') has_lower = 1;
    else if (c >= '0' && c <= '9') has_digit = 1;
}

return (has_upper && has_lower && has_digit) ? 1 : 0;
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
