#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    if (token == NULL) return 0;

    size_t len = strlen(token);
    /* basic length check */
    if (len < 10 || len > 4096) return 0;

    /* Expect a JWT-like token with exactly two dots and non-empty segments.
       Each segment must contain only base64url characters: A-Z a-z 0-9 - _ */
    int dots = 0;
    const char *seg_start = token;
    for (const char *p = token; *p != '\0'; ++p) {
        char c = *p;
        if (c == '.') {
            /* empty segment (e.g. ".." or starts/ends with '.') is invalid */
            if (p == seg_start) return 0;
            dots++;
            seg_start = p + 1;
            continue;
        }
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == '-' || c == '_')) {
            return 0;
        }
    }

    /* last segment must be non-empty */
    if (seg_start == token + len) return 0;
    /* require exactly two dots for a three-part token */
    return (dots == 2) ? 1 : 0;
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
