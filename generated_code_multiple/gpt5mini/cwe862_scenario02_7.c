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

    /* Build permission check input safely */
    char input[1024];
    int n = snprintf(input, sizeof input, "%s=%s", key, value);
    if (n < 0 || n >= (int)sizeof input) return 1;

    /* Ensure key/value do not contain newline characters */
    for (const char *p = key; *p; ++p) {
        if (*p == '\n' || *p == '\r') return 1;
    }
    for (const char *p = value; *p; ++p) {
        if (*p == '\n' || *p == '\r') return 1;
    }

    /* Check permissions */
    if (check_perms(input) != 0) return 1;

    /* Append/update the configuration (simple append here) */
    FILE *f = fopen("config.cfg", "a");
    if (!f) return 1;
    if (fprintf(f, "%s=%s\n", key, value) < 0) {
        fclose(f);
        return 1;
    }
    if (fclose(f) != 0) return 1;

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}