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

    /* Create a mutable copy of value for check_perms */
    char *tmp = strdup(value);
    if (tmp == NULL) {
        return -1;
    }

    int rc = check_perms(tmp);
    free(tmp);

    if (rc != 0) {
        return rc;
    }

    /* Simulate updating configuration (e.g., writing to a file or DB).
       For this example, just print the key/value pair. */
    if (printf("Config updated: %s = %s\n", key, value) < 0) {
        return -1;
    }

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}