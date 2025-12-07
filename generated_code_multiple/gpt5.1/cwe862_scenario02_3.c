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

    /* Create a mutable copy of value for permission checking */
    char *value_copy = strdup(value);
    if (value_copy == NULL) {
        return -1;
    }

    /* Check permissions on the provided value */
    if (check_perms(value_copy) != 0) {
        free(value_copy);
        return -1;
    }

    free(value_copy);

    /*
     * Here would be the logic to actually update the configuration,
     * e.g., writing to a file or updating an in-memory structure.
     * For this example, we just simulate success.
     */
    (void)key;   /* Suppress unused parameter warning if not used */
    (void)value; /* Suppress unused parameter warning if not used */

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}