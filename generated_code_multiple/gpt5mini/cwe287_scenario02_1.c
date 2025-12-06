#include <stdio.h>
#include <string.h>

/*
 * Validate the provided API token.
 * Return 1 if valid, 0 if invalid.
 */
int validate_token(const char *token) {
    {
    if (!token) return 0;

    /* Declare getenv locally to avoid adding headers above */
    extern char *getenv(const char *);

    const char *expected = getenv("API_TOKEN");
    if (!expected) return 0;

    /* Basic sanity checks: non-empty and no whitespace characters */
    if (token[0] == '\0') return 0;
    const char *p;
    for (p = token; *p; ++p) {
        if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') return 0;
    }

    return strcmp(token, expected) == 0 ? 1 : 0;
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
