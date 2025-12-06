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
    if (!key || !value) {
        return -1; // Invalid arguments
    }

    // For demonstration purposes, we'll just print the update.
    // In a real scenario, you would interact with a configuration file
    // or system settings here.
    printf("Updating config: %s = %s\n", key, value);

    // Assuming check_perms is used to validate the input, though its
    // exact purpose isn't fully defined here.
    // If check_perms returns non-zero, it indicates a failure.
    if (check_perms((char *)value) != 0) {
        fprintf(stderr, "Permission check failed for value: %s\n", value);
        return -1; // Failure due to permission check
    }

    // In a real implementation, you would write to a configuration file,
    // update a database, or call system APIs to change the setting.
    // For this example, we'll assume success if the above checks pass.
    return 0; // Success
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}