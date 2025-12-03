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
        fprintf(stderr, "Invalid key or value\n");
        return -1;
    }

    if (check_perms("config")) {
        fprintf(stderr, "Permission check failed\n");
        return -1;
    }

    // Simulate updating the configuration
    printf("Updating config: %s = %s\n", key, value);

    // Assume the update is successful
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}