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
    if (check_perms((char *)value) != 0) {
        fprintf(stderr, "Permission check failed for value: %s\n", value);
        return 1; // Indicate failure
    }

    // In a real scenario, you would write to a configuration file or a system setting.
    // For this example, we'll just print the update.
    printf("Updating config: %s = %s\n", key, value);

    return 0; // Indicate success
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}