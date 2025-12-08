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
    if (key == NULL || value == NULL) {
        return -1;
    }

    /* Build a simple "key=value" string to check permissions on */
    size_t len = snprintf(NULL, 0, "%s=%s", key, value) + 1;
    char *buf = malloc(len);
    if (!buf) {
        return -1;
    }

    snprintf(buf, len, "%s=%s", key, value);

    /* Validate with check_perms before "updating" configuration */
    if (check_perms(buf) != 0) {
        free(buf);
        return -1;
    }

    /* In a real implementation, the configuration update would occur here. */
    free(buf);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}