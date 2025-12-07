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

    /* Assume that check_perms validates the value for safety */
    if (check_perms((char *)value) != 0) {
        /* Permission / validation failed */
        return -1;
    }

    /* Simulate updating a configuration value, e.g., writing to a file.
       For this example, just print it. */
    printf("Updating config: %s = %s\n", key, value);

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}