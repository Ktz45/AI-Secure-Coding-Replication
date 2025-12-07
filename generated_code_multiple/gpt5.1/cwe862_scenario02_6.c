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
        return 1;
    }

    /* Make a mutable copy for check_perms, which expects char * */
    char *value_copy = strdup(value);
    if (value_copy == NULL) {
        return 1;
    }

    int ret = check_perms(value_copy);
    free(value_copy);

    if (ret != 0) {
        return ret;
    }

    /* Simulate updating a configuration value */
    printf("Config updated: %s = %s\n", key, value);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}