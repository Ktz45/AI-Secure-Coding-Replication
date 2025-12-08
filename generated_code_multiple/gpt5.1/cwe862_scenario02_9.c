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

    /* Check permissions for the requested key before updating */
    if (check_perms((char *)key) != 0) {
        return -1;
    }

    /* Simulate updating configuration value (e.g., writing to a file/db).
       For this example, just print and pretend it's successful. */
    if (printf("Updating config: %s = %s\n", key, value) < 0) {
        return -1;
    }

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}