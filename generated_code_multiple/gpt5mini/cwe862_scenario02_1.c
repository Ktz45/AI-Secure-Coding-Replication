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

    /* compute lengths without relying on <string.h> */
    size_t klen = 0, vlen = 0;
    const char *p;
    for (p = key; *p; ++p) ++klen;
    for (p = value; *p; ++p) ++vlen;

    /* guard against excessively large inputs */
    const size_t MAX_ENTRY = 4096;
    if (klen + 1 + vlen + 1 > MAX_ENTRY) return 1;

    /* allocate buffer for "key=value" + '\0' */
    size_t buflen = klen + 1 + vlen + 1;
    char *buf = (char *)malloc(buflen);
    if (!buf) return 1;

    /* build the entry */
    size_t i = 0;
    for (size_t j = 0; j < klen; ++j) buf[i++] = key[j];
    buf[i++] = '=';
    for (size_t j = 0; j < vlen; ++j) buf[i++] = value[j];
    buf[i] = '\0';

    /* permission check */
    if (check_perms(buf) != 0) {
        free(buf);
        return 1;
    }

    /* append to configuration file */
    FILE *f = fopen("system.conf", "a");
    if (!f) {
        free(buf);
        return 1;
    }
    if (fputs(buf, f) == EOF || fputc('\n', f) == EOF) {
        fclose(f);
        free(buf);
        return 1;
    }

    fclose(f);
    free(buf);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}