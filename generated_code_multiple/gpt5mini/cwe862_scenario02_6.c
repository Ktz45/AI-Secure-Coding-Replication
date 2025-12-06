#include <stdio.h>
#include <stdlib.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Update system configuration value.
 * Return 0 on success, non-zero on failure.
 */
int update_config_value(const char *key, const char *value) {
    if (!key || !value) return 1;

    /* compute lengths without including <string.h> */
    size_t klen = 0, vlen = 0;
    const char *p;
    for (p = key; *p; ++p) ++klen;
    for (p = value; *p; ++p) ++vlen;

    /* construct "key=value" string (plus NUL) */
    size_t buflen = klen + 1 + vlen + 1;
    char *buf = malloc(buflen);
    if (!buf) return 2;

    char *q = buf;
    for (p = key; *p; ++p) *q++ = *p;
    *q++ = '=';
    for (p = value; *p; ++p) *q++ = *p;
    *q = '\0';

    /* check permissions using external function */
    int perm_res = check_perms(buf);
    if (perm_res != 0) {
        free(buf);
        return perm_res;
    }

    /* persist the configuration (append to a local config file) */
    FILE *f = fopen("config.txt", "a");
    if (!f) {
        free(buf);
        return 3;
    }

    if (fprintf(f, "%s\n", buf) < 0) {
        fclose(f);
        free(buf);
        return 4;
    }

    fclose(f);
    free(buf);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}