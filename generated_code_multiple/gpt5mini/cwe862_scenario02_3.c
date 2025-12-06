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
    int needed = snprintf(NULL, 0, "%s=%s", key, value);
    if (needed < 0) return 1;
    char *input = malloc((size_t)needed + 1);
    if (!input) return 1;
    snprintf(input, (size_t)needed + 1, "%s=%s", key, value);
    int rc = check_perms(input);
    free(input);
    if (rc != 0) return rc;
    /* Permission granted; configuration update would occur here.
       For this example we consider the update successful. */
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}